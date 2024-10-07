#ifndef PC_OUTPUT_HANDLER_H
#define PC_OUTPUT_HANDLER_H

#include <string>

#include "../ds/output_handler.h"

namespace ds::pc
{
    class PCOutputHandler : public ds::OutputHandler
    {
    public:
        void print(const std::string text) const;
        void println(const std::string text = "") const;
        void flush() const;
    };
}  // namespace ds::pc

#endif /* PC_OUTPUT_HANDLER_H */