#include "help_command.h"

HelpCommand::HelpCommand(ArgumentendCommandParser *parser) : _parser(parser) {}

bool HelpCommand::execute()
{
    // TODO: Only show `Subcommands` and `Arguments` headers when there is
    // something to show

    std::cout << "\nSubcommands:\n";
    for (const auto &subparser : _parser->get_parsers())
    {
        if (!subparser.second->show_in_help()) continue;
        std::cout << "  " << std::left << std::setw(24) << subparser.first
                  << subparser.second->get_description() << "\n";
    }

    std::cout << "\nArguments:\n";
    for (const auto &argument : _parser->get_argumentes())
    {
        std::string name = argument->get_name();
        if (argument->is_required())
        {
            name = "<" + name + ">";
        }

        std::cout << "  " << std::left << std::setw(24) << name
                  << argument->get_description() << "\n";
    }
    std::cout << '\n';

    return true;
}