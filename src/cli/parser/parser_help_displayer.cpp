#include "parser_help_displayer.h"

ParserHelpDisplayer::ParserHelpDisplayer(const Parser &parser) : _parser(parser)
{
}

void ParserHelpDisplayer::display_help() const
{
    std::cout << "Help for parser: " << _parser.get_description() << std::endl
              << std::endl;
    const auto &subparsers = _parser.get_parsers();
    if (subparsers.size() > 0)
    {
        std::cout << "Subcommands:\n";
        for (const auto &sub_parser : subparsers)
            std::cout << "  " << std::left << std::setw(16) << sub_parser.first
                      << " " << sub_parser.second->get_description()
                      << std::endl;
    }
}