#include "help_command.h"

HelpCommand::HelpCommand(ArgumentendCommandParser *parser) : _parser(parser) {}

bool HelpCommand::execute()
{
    // TODO: Implement help command
    // - Get all subparsers from the given parser
    // - Get all arguments from the given parser

    std::cout << "Subcommands:\n";
    for (const auto &subparser : _parser->get_parsers())
    {
        std::cout << "  " << subparser.first << " - "
                  << subparser.second->get_description() << "\n";
    }

    std::cout << "Arguments:\n";
    for (const auto &argument : _parser->get_argumentes())
    {
        std::cout << "  " << argument->get_name() << " - "
                  << argument->get_description() << "\n";
    }

    return true;
}