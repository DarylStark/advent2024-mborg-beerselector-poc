#include "pc_input_handler.h"

#include <fstream>
#include <iostream>

namespace ds::pc
{
    std::string PCInputHandler::get_string() const
    {
        std::string buffer;
        std::getline(std::cin, buffer);

        if (std::cin.eof())
        {
            // Handle EOF (CTRL+D)
            std::clearerr(stdin);
            std::cin.clear();
            return "";
        }
        if (!std::cin.good())
        {
            // Handle other input errors
            std::cin.clear();  // Clear the error state
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }

        return buffer;
    }

    bool PCInputHandler::is_mode_pressed() const
    {
        std::ifstream file("mode.txt");
        return file.good();
    }
}  // namespace ds::pc