#include "rommon_state.h"

#include "../cli/model/rommon/cli_parser_rommon_factory.h"
#include "../cli/parser/argumented_command_parser.h"

RommonState::RommonState(std::shared_ptr<ds::PlatformObjectFactory> factory,
                         ds::BaseApplication &application)
    : ds::BaseState(factory, application),
      _output_handler(_factory->get_output_handler()),
      _input_handler(_factory->get_input_handler())
{
}

void RommonState::loop()
{
    _output_handler->println("INITIALIZING ROMMON\n\n");

    CLIParserROMMONFactory parser_factory;
    std::shared_ptr<ArgumentendCommandParser> word_parser =
        parser_factory.get_parser();

    _output_handler->println("ROMMON INITIALIZED\n\n");

    // Command line
    while (true)
    {
        std::string command;
        std::cout << "# ";
        std::getline(std::cin, command);
        if (!std::cin.good()) break;

        std::stringstream iss(command);
        std::vector<std::string> words(std::istream_iterator<std::string>{iss},
                                       std::istream_iterator<std::string>());

        // Parse
        word_parser->parse(words);
    }
}