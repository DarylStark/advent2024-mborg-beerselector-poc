#ifndef __PC_INPUT_HANDLER_H__
#define __PC_INPUT_HANDLER_H__

#include <limits>
#include <string>

#include "../ds/input_handler.h"

namespace ds::pc
{
    class PCInputHandler : public ds::InputHandler
    {
    public:
        std::string get_string() const;

        bool is_mode_pressed() const;
    };
}  // namespace ds::pc

#endif /* __PC_INPUT_HANDLER_H__ */