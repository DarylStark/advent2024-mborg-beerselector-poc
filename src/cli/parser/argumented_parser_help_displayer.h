#ifndef __ARGUMENT_HELP_DISPLAYER_H__
#define __ARGUMENT_HELP_DISPLAYER_H__

#include "argumented_command_parser.h"
#include "parser_help_displayer.h"

class ArgumentedParserHelpDisplayer : public ParserHelpDisplayer
{
protected:
    const ArgumentendCommandParser &_parser;

public:
    ArgumentedParserHelpDisplayer(const ArgumentendCommandParser &parser);
    void display_help() const;
};

#endif /* __ARGUMENT_HELP_DISPLAYER_H__ */