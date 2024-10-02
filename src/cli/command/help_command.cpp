#include "help_command.h"

#define COMMAND_COLUMN_LENGTH 24

HelpCommand::HelpCommand(ArgumentendCommandParser *parser) : _parser(parser) {}

bool HelpCommand::execute(std::map<std::string, std::string> args)
{
    // TODO: Only show `Subcommands` and `Arguments` headers when there is
    // something to show

    std::cout << '\n' << _parser->get_help() << "\n";

    std::cout << "\nSubcommands:\n";
    for (const auto &subparser : _parser->get_parsers())
    {
        if (!subparser.second->show_in_help()) continue;
        std::cout << "  " << std::left << std::setw(COMMAND_COLUMN_LENGTH)
                  << subparser.first << subparser.second->get_description()
                  << "\n";
    }

    std::cout << "\nArguments:\n";
    for (const auto &argument : _parser->get_argumentes())
    {
        std::stringstream arg_name;
        if (argument->is_required())
        {
            arg_name << "<" << argument->get_name() << ">";
        }
        else
        {
            arg_name << "[" << argument->get_name() << "]";
        }

        std::cout << "  " << std::left << std::setw(COMMAND_COLUMN_LENGTH)
                  << arg_name.str() << argument->get_description() << "\n";
    }
    std::cout << '\n';

    return true;
}