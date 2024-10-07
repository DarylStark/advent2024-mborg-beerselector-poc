#ifndef CLI_PARSER_ROMMON_FACTORY_H
#define CLI_PARSER_ROMMON_FACTORY_H

#include "../cli_model.h"
#include "../shared/cli_shared_parsers.h"

class CLIParserROMMONFactory : public CLIParserFactory
{
private:
    static std::shared_ptr<ArgumentedCommandParser> _parser;

    std::shared_ptr<ArgumentedCommandParser> _create_parser();
    std::shared_ptr<ArgumentedCommandParser> _get_auth_parser();

public:
    std::shared_ptr<ArgumentedCommandParser> get_parser();
};

#endif /* CLI_PARSER_ROMMON_FACTORY_H */
