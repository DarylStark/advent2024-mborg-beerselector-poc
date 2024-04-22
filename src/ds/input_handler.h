#ifndef __INPUT_HANDLER_H__
#define __INPUT_HANDLER_H__

#include <string>

namespace ds
{
    class InputHandler
    {
        // Interface for Input Handlers.
    public:
        // Methods to retrieve data
        virtual std::string get_string() const = 0;

        // Methods to check if a specific button is pressed
        virtual bool is_mode_pressed() const = 0;
    };
}

#endif /* __INPUT_HANDLER_H__ */