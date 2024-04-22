#ifndef __PC_INPUT_HANDLER_H__
#define __PC_INPUT_HANDLER_H__

#include <string>
#include "../ds/input_handler.h"

namespace ds::pc
{
    class PCInputHandler : public ds::InputHandler
    {
    public:
        std::string get_string() const;
    };
}

#endif /* __PC_INPUT_HANDLER_H__ */