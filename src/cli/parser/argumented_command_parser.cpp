#include "argumented_command_parser.h"

#include "../command/help_command.h"

ArgumentendCommandParser::ArgumentendCommandParser(
    const std::string description, const std::string help,
    std::shared_ptr<Command> command, bool add_helper, bool show_in_help)
    : Parser(description, help, show_in_help), _required_arguments(0),
      _command(command)
{
    if (add_helper)
    {
        auto help_command = std::make_shared<HelpCommand>(this);
        this->add_parser("?", std::make_shared<ArgumentendCommandParser>(
                                  "Help about this command", "", help_command,
                                  false, false));
        this->add_parser(
            "help", std::make_shared<ArgumentendCommandParser>(
                        "Help about this command", "", help_command, false));
    }
}

bool ArgumentendCommandParser::parse(std::vector<std::string> arguments)
{
    std::map<std::string, std::string> argument_map;
    if (arguments.size() > 0)
    {
        // Command to parse
        std::string command = arguments[0];

        // Check if it is an subparser
        std::shared_ptr<Parser> parser = get_parser(command);
        if (parser != nullptr)
        {
            std::vector<std::string> sub_arguments(arguments.begin() + 1,
                                                   arguments.end());
            return parser->parse(sub_arguments);
        }

        // It wasn't a subparser, so it must be an argument
        unsigned long argument_nr = 0;
        for (const auto &argument : arguments)
        {
            if (argument_nr >= _arguments.size())
            {
                // TODO: Throw exception about too many arguments
                std::cerr << "Unrecognized argument: \"" << argument << "\"\n";
                return true;
            }

            const auto &argument_object = _arguments[argument_nr];
            argument_object->parse(argument);
            argument_nr++;

            // Add it to the argument map
            argument_map[argument_object->get_name()] = argument;
        }
    }

    // Check if all required arguments are set
    if (argument_map.size() < _required_arguments)
    {
        std::cout << "MISSING ARGUMENTS!\n\n\n";
    }

    // Everything is parsed! Let's execute the command!
    return execute(argument_map);
}

bool ArgumentendCommandParser::execute(
    std::map<std::string, std::string> args) const
{
    if (_command) return _command->execute();

    std::cerr << "This command is not implemented\n";
    return true;
}

void ArgumentendCommandParser::add_argument(std::shared_ptr<Argument> argument)
{
    // Check if the last argument in _argument was required and if so, throw
    // an exception
    if (_arguments.size() > 0 && _arguments.back()->is_required() &&
        !argument->is_required())
        std::cout << "Adding non-required argument after required "
                     "argument. ERROR.\n\n";
    _required_arguments += argument->is_required();
    _arguments.push_back(argument);
}

const std::vector<std::shared_ptr<Argument>>
    &ArgumentendCommandParser::get_argumentes() const
{
    return _arguments;
}
