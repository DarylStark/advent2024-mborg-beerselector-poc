#ifndef __CLI_SHARED_PARSERS_H__
#define __CLI_SHARED_PARSERS_H__

#include "../cli_model.h"

class CLISharedParser
{
public:
    static std::shared_ptr<ArgumentendCommandParser> get_reload_parser();
};

class CLIReloadParserFactory : public CLIParserFactory
{
private:
    static std::shared_ptr<ArgumentendCommandParser> _parser;
    std::shared_ptr<ArgumentendCommandParser> _create_parser();

public:
    std::shared_ptr<ArgumentendCommandParser> get_parser();
};

#endif /* __CLI_SHARED_PARSERS_H__ */
