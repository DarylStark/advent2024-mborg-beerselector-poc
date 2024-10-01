#include "parser.h"

Parser::Parser(const std::string description) : _description(description) {}

std::shared_ptr<Parser> Parser::add_parser(std::string name,
                                           std::shared_ptr<Parser> parser)
{
    _parsers[name] = parser;
    return parser;
}

std::shared_ptr<Parser> Parser::get_parser(std::string name) const
{
    try
    {
        return _parsers.at(name);
    }
    catch (const std::out_of_range &e)
    {
        return nullptr;
    }
}

void Parser::delete_parser(std::string name)
{
    _parsers.erase(name);
}

const std::string &Parser::get_description() const
{
    return _description;
}

const std::map<std::string, std::shared_ptr<Parser>> &Parser::get_parsers()
    const
{
    return _parsers;
}