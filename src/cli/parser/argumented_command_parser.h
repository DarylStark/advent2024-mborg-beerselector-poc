#ifndef ARGUMENTED_COMMAND_PARSER_H
#define ARGUMENTED_COMMAND_PARSER_H

#include "argument.h"
#include "parser.h"

class ArgumentendCommandParser : public Parser
{
private:
    std::vector<std::shared_ptr<Argument>> _arguments;
    uint32_t _required_arguments;

public:
    ArgumentendCommandParser(const std::string description = std::string(""));
    virtual void parse(std::vector<std::string> arguments) override;
    virtual void execute(std::map<std::string, std::string> args) const;
    void add_argument(std::shared_ptr<Argument> argument);
    const std::vector<std::shared_ptr<Argument>> &get_argumentes() const;
};

#endif /* ARGUMENTED_COMMAND_PARSER_H */
