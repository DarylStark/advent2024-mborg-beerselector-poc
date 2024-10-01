#ifndef HELD_COMMAND_H
#define HELD_COMMAND_H

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

#endif /* HELD_COMMAND_H */