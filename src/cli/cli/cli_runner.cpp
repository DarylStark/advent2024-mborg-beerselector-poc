#include "cli_runner.h"

#include <iostream>

#include "../parser/exceptions.h"

std::shared_ptr<ds::PlatformObjectFactory> CLIRunner::_factory = nullptr;

CLIRunner::CLIRunner(std::shared_ptr<ArgumentedCommandParser> parser,
                     const std::string prompt)
    : _parser(parser), _prompt(prompt)
{
    if (_factory == nullptr)
        throw std::runtime_error(
            "PlatformObjectFactory not set for the CLIRunner class");
}

void CLIRunner::set_factory(std::shared_ptr<ds::PlatformObjectFactory> factory)
{
    _factory = factory;
}

void CLIRunner::set_prompt(const std::string prompt)
{
    _prompt = prompt;
}

bool CLIRunner::run()
{
    const auto& output_handler = _factory->get_output_handler();
    const auto& input_handler = _factory->get_input_handler();

    while (true)
    {
        output_handler->print(_prompt);
        std::string command = input_handler->get_string();

        std::stringstream iss(command);
        std::vector<std::string> words(std::istream_iterator<std::string>{iss},
                                       std::istream_iterator<std::string>());

        if (words.empty()) continue;

        // Parse
        try
        {
            return _parser->parse(words);
        }
        catch (const ParseException& e)
        {
            output_handler->println(e.what());
            return true;
        }
    }
}