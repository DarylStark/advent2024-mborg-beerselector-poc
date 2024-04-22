#include <iostream>
#include "pc_input_handler.h"

namespace ds::pc
{
    std::string PCInputHandler::get_string() const
    {
        std::string buffer;
        std::getline(std::cin, buffer);
        return buffer;
    }
}