#include <memory>
#include "pc/pc_object_factory.h"
#include "beer_selector/beer_selector.h"

// Dependencies
std::shared_ptr<ds::PlatformObjectFactory> pof = std::make_shared<ds::pc::PCObjectFactory>();

// App object. Dependencies get injected
std::shared_ptr<ds::BaseApplication> my_app = std::make_shared<BeerSelector>(
    pof // Platform specific object factory
);

void setup()
{
    my_app->setup();
}

void loop()
{
    my_app->loop();
}