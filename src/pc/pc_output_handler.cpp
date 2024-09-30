#include "pc_output_handler.h"

#include <iostream>

namespace ds::pc {
    void PCOutputHandler::print(const std::string text) const {
        std::cout << text;
    }

    void PCOutputHandler::println(const std::string text) const {
        std::cout << text << "\n";
    }

    void PCOutputHandler::flush() {
        std::flush(std::cout);
    }
}  // namespace ds::pc