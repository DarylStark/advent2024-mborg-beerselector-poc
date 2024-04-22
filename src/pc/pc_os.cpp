#include "pc_os.h"

#include <thread>
#include <chrono>

#include <iostream>

namespace ds::pc
{
    void PCOS::sleep_miliseconds(uint32_t miliseconds)
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(miliseconds));
    }
}