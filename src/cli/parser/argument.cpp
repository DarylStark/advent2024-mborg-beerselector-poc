#include "argument.h"

Argument::Argument(std::string name, bool required,
                   const std::string &description)
    : _name(name), _description(description), _required(required)
{
}

const std::string &Argument::get_name() const
{
    return _name;
}

bool Argument::is_required() const
{
    return _required;
}

const std::string &Argument::get_description() const
{
    return _description;
}

void StaticArgument::parse(std::string argument)
{
    // TODO: Implement code to check if this argument is valid
    if (argument != _expected_value)
    {
        std::cerr << "WRONG VALUE FOR ARGUMENT " << get_name() << ": "
                  << argument << " (expected: " << _expected_value << ")\n";
    }
}

EnumArgument::EnumArgument(std::string name,
                           std::vector<std::string> possibilities,
                           bool required, const std::string description)
    : Argument(name, required, description), _possibilities(possibilities)
{
}

void EnumArgument::parse(std::string argument)
{
    auto it = std::find(_possibilities.begin(), _possibilities.end(), argument);
    if (it == _possibilities.end())
    {
        std::cerr << "WRONG VALUE FOR ARGUMENT " << get_name() << ": "
                  << argument << " (expected one of: ";
        for (const auto &possibility : _possibilities)
        {
            std::cerr << possibility << ", ";
        }
        std::cerr << ")\n";
    }
}

void StringArgument::parse(std::string argument)
{
    std::cout << "Argument " << argument << " is given.";
}

void IntArgument::parse(std::string argument)
{
    try
    {
        int value = std::stoi(argument);
        std::cout << "Argument " << argument << " is an integer ";
        std::cout << "with value " << value;
    }
    catch (const std::invalid_argument &e)
    {
        std::cerr << "WRONG VALUE FOR ARGUMENT " << get_name() << ": "
                  << argument << " (expected an integer)\n";
    }
}