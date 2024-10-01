#include "argumented_parser_help_displayer.h"

ArgumentedParserHelpDisplayer::ArgumentedParserHelpDisplayer(
    const ArgumentendCommandParser &parser)
    : ParserHelpDisplayer(parser), _parser(parser)
{
}

void ArgumentedParserHelpDisplayer::display_help() const
{
    ParserHelpDisplayer::display_help();
    const auto &arguments = _parser.get_argumentes();
    if (arguments.size() > 0)
    {
        std::cout << "Arguments:\n";
        for (const auto &argument : arguments)
            std::cout << "  " << std::left << std::setw(16)
                      << argument->get_name() << " "
                      << argument->get_description() << std::endl;
    }
}