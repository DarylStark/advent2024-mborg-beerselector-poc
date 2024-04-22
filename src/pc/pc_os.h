#ifndef __PC_OS_H__
#define __PC_OS_H__

#include "../ds/os.h"

namespace ds::pc
{
    class PCOS : public ds::OS
    {
    public:
        void sleep_miliseconds(uint32_t miliseconds);
    };
}

#endif /* __PC_OS_H__ */