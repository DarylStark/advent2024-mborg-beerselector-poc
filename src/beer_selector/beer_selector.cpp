#include <sstream>
#include <iomanip>
#include "beer_selector.h"
#include "booting_state.h"

BeerSelector::BeerSelector(std::shared_ptr<ds::PlatformObjectFactory> factory)
    : ds::BaseApplication(factory)
{
    _output_handler = _factory->get_output_handler();
    _input_handler = _factory->get_input_handler();
}

void BeerSelector::setup()
{
    // Set the state to booting. The booting state will switch to the correct
    // state after booting. This can be a few states, based on the boot
    // conditions.

    _factory->get_os()->sleep_miliseconds(1000);
    set_state(std::make_shared<BootingState>(_factory, *this));

    // _output_handler->print("Retrieving configuration register ... ");
    // _output_handler->flush();
    // _factory->get_os()->sleep_miliseconds(1000);
    // _output_handler->println("DONE");
}

void BeerSelector::loop()
{
    _state->loop();
}
