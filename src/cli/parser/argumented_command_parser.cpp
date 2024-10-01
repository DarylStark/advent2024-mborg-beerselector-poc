#include "argumented_command_parser.h"

ArgumentendCommandParser::ArgumentendCommandParser(
    const std::string description)
    : Parser(description)
{
}

void ArgumentendCommandParser::parse(std::vector<std::string> arguments)
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
            parser->parse(sub_arguments);
            return;
        }

        // It wasn't a subparser, so it must be an argument
        unsigned long argument_nr = 0;
        for (const auto &argument : arguments)
        {
            if (argument_nr >= _arguments.size())
            {
                // TODO: Throw exception about too many arguments
                std::cerr << "Unrecognized argument: \"" << argument << "\"\n";
                return;
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
    execute(argument_map);
}

void ArgumentendCommandParser::execute(
    std::map<std::string, std::string> args) const
{
    std::cout << "\n\nHello, running command with the following arguments:"
              << std::endl;
    for (const auto &argument : _arguments)
    {
        std::cout << "> " << argument->get_name();
        if (args.find(argument->get_name()) != args.end())
        {
            std::cout << ": \"" << args.at(argument->get_name()) << "\""
                      << std::endl;
        }
        else
        {
            std::cout << " (not set)" << std::endl;
        }
    }
    std::cout << "\n\n";
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