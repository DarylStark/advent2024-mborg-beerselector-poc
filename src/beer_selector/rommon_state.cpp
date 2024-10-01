#include "rommon_state.h"

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

    ArgumentendCommandParser word_parser("ROMMON");

    // Auth
    std::shared_ptr<ArgumentendCommandParser> auth =
        std::make_shared<ArgumentendCommandParser>("Authentication details");

    // auth credentials <username> <password>
    std::shared_ptr<ArgumentendCommandParser> running_config =
        std::make_shared<ArgumentendCommandParser>(
            "Show in-memory configuration");
    auth->add_parser("credentials", running_config);
    running_config->add_argument(std::make_shared<StringArgument>(
        "username", true, "The username to set"));
    running_config->add_argument(std::make_shared<StringArgument>(
        "password", true, "The password to set"));

    // Auth
    std::shared_ptr<ArgumentendCommandParser> help =
        std::make_shared<ArgumentendCommandParser>("Command line help");

    // Add parsers
    word_parser.add_parser("auth", auth);
    word_parser.add_parser("help", help);

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
        word_parser.parse(words);
    }
}