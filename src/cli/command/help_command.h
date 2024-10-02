#ifndef HELP_COMMAND_H
#define HELP_COMMAND_H

#include <iomanip>
#include <iostream>

#include "../parser/argumented_command_parser.h"
#include "command.h"

class HelpCommand : public Command
{
private:
    ArgumentendCommandParser* _parser;

public:
    HelpCommand(ArgumentendCommandParser* parser);
    bool execute() override;
};

#endif /* HELP_COMMAND_H */