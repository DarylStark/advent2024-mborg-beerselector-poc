#include "pc_input_handler.h"

#include <fstream>
#include <iostream>

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
        std::ifstream file("mode.txt");
        return file.good();
    }
}  // namespace ds::pc