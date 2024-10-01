#include "./cli_shared_parsers.h"

std::shared_ptr<ArgumentendCommandParser> CLISharedParser::get_reload_parser()
{
    return CLIReloadParserFactory().get_parser();
}

// Specific parsers

std::shared_ptr<ArgumentendCommandParser> CLIReloadParserFactory::_parser =
    nullptr;

std::shared_ptr<ArgumentendCommandParser>
CLIReloadParserFactory::_create_parser()
{
    // Parser for the ROMMON mode
    std::shared_ptr<ArgumentendCommandParser> parser =
        std::make_shared<ArgumentendCommandParser>("Reload",
                                                   "Reload the device.");

    return parser;
}

std::shared_ptr<ArgumentendCommandParser> CLIReloadParserFactory::get_parser()
{
    if (!_parser) _parser = _create_parser();
    return _parser;
}