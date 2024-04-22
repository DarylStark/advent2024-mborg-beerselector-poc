#include "rommon_state.h"

RommonState::RommonState(std::shared_ptr<ds::PlatformObjectFactory> factory, ds::BaseApplication &application)
    : ds::BaseState(factory, application), _output_handler(_factory->get_output_handler()), _input_handler(_factory->get_input_handler())
{
}

void RommonState::loop()
{
    _output_handler->println("ROMMON INITIALIZED\n\n");
    _factory->get_os()->sleep_miliseconds(100);
}