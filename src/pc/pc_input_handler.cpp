#include <iostream>
#include <fstream>
#include "pc_input_handler.h"

namespace ds::pc
{
    std::string PCInputHandler::get_string() const
    {
        std::string buffer;
        std::getline(std::cin, buffer);
        return buffer;
    }

    bool PCInputHandler::is_mode_pressed() const
    {
        std::ifstream file("enter.txt");
        return file.good();
    }
}