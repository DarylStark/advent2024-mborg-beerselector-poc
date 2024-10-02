#ifndef COMMAND_H
#define COMMAND_H

#include <map>
#include <string>

class Command
{
public:
    virtual bool execute(std::map<std::string, std::string> args) = 0;
};

#endif /* COMMAND_H */