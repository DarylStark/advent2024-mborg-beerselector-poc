#ifndef __PARSER_HELP_DISPLAYER_H__
#define __PARSER_HELP_DISPLAYER_H__

#include <iomanip>
#include <iostream>

#include "parser.h"

class ParserHelpDisplayer
{
protected:
    const Parser &_parser;

public:
    ParserHelpDisplayer(const Parser &parser);
    virtual void display_help() const;
};

#endif /* __PARSER_HELP_DISPLAYER_H__ */