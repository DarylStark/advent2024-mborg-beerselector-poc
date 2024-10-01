#ifndef __PARSER_H__
#define __PARSER_H__

#include <map>
#include <memory>
#include <string>
#include <vector>

class Parser
{
protected:
    std::map<std::string, std::shared_ptr<Parser>> _parsers;
    const std::string _description;

public:
    Parser(const std::string description = std::string(""));
    std::shared_ptr<Parser> add_parser(std::string name,
                                       std::shared_ptr<Parser> parser);
    void delete_parser(std::string name);
    std::shared_ptr<Parser> get_parser(std::string name) const;

    virtual void parse(std::vector<std::string> arguments) = 0;
    virtual void execute(std::map<std::string, std::string> args) const = 0;

    const std::string &get_description() const;
    const std::map<std::string, std::shared_ptr<Parser>> &get_parsers() const;
};

#endif /* __CMDLINE_PARSER_H */