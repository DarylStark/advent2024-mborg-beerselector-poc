#ifndef __CLI_RUNNER_H__
#define __CLI_RUNNER_H__

#include <iostream>
#include <iterator>
#include <limits>
#include <memory>
#include <sstream>

#include "../../cli/parser/argumented_command_parser.h"


class CLIRunner
{
private:
    std::shared_ptr<ArgumentendCommandParser> _parser;
    std::string _prompt;

public:
    CLIRunner(std::shared_ptr<ArgumentendCommandParser> parser,
              const std::string prompt);
    void set_prompt(const std::string prompt);
    bool run();
};

#endif /* __CLI_RUNNER_H__ */