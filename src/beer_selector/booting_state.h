#ifndef __BOOTING_STATE_H__
#define __BOOTING_STATE_H__

#include "app_info.h"
#include "../ds/base_state.h"

#define SECONDS_WAIT_FOR_KEYPRESS 10

class BootingState : public ds::BaseState
{
private:
    std::shared_ptr<ds::OutputHandler> _output_handler;
    std::shared_ptr<ds::InputHandler> _input_handler;

    void _print_logo() const;
    void _print_device_information() const;
    void _wait_for_keypress_rommon();
    void _go_to_rommon();

public:
    BootingState(std::shared_ptr<ds::PlatformObjectFactory> factory, ds::BaseApplication &application);
    void loop();
};

#endif /* __BOOTING_STATE_H__ */