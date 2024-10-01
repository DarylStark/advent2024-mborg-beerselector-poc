#ifndef __CLI_PARSER_ROMMON_FACTORY_H__
#define __CLI_PARSER_ROMMON_FACTORY_H__

#include "../cli_model.h"

class CLIParserROMMONFactory : public CLIParserFactory
{
private:
    static std::shared_ptr<ArgumentendCommandParser> _parser;

    std::shared_ptr<ArgumentendCommandParser> _create_parser();
    std::shared_ptr<ArgumentendCommandParser> _get_auth_parser();

public:
    std::shared_ptr<ArgumentendCommandParser> get_parser();
};

#endif /* __CLI_PARSER_ROMMON_FACTORY_H__ */
