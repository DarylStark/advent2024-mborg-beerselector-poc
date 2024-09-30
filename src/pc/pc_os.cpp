#include "pc_os.h"

#include <chrono>
#include <iostream>
#include <thread>

namespace ds::pc
{
    void PCOS::sleep_miliseconds(uint32_t miliseconds)
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(miliseconds));
    }
}  // namespace ds::pc