#ifndef PC_OS_H
#define PC_OS_H

#include "../ds/os.h"

namespace ds::pc
{
    class PCOS : public ds::OS
    {
    public:
        void sleep_miliseconds(uint32_t miliseconds);
    };
}  // namespace ds::pc

#endif /* PC_OS_H */