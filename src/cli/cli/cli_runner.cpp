#include "cli_runner.h"

CLIRunner::CLIRunner(std::shared_ptr<ArgumentendCommandParser> parser,
                     const std::string prompt)
    : _parser(parser), _prompt(prompt)
{
}

void CLIRunner::set_prompt(const std::string prompt)
{
    _prompt = prompt;
}

bool CLIRunner::run()
{
    std::string command;
    std::cout << _prompt;
    std::getline(std::cin, command);

    if (std::cin.eof())
    {
        // Handle EOF (CTRL+D)
        std::clearerr(stdin);
        std::cin.clear();
        return false;
    }
    if (!std::cin.good())
    {
        // Handle other input errors
        std::cin.clear();  // Clear the error state
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    std::stringstream iss(command);
    std::vector<std::string> words(std::istream_iterator<std::string>{iss},
                                   std::istream_iterator<std::string>());

    // Parse
    return _parser->parse(words);
}