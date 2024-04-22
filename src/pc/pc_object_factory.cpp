#include "pc_object_factory.h"
#include "pc_output_handler.h"
#include "pc_input_handler.h"
#include "pc_os.h"

namespace ds::pc
{
    std::shared_ptr<ds::OutputHandler> PCObjectFactory::get_output_handler()
    {
        // TODO: cache this object and return the cached version
        return std::make_shared<PCOutputHandler>();
    }

    std::shared_ptr<ds::InputHandler> PCObjectFactory::get_input_handler()
    {
        // TODO: cache this object and return the cached version
        return std::make_shared<PCInputHandler>();
    }

    std::shared_ptr<ds::OS> PCObjectFactory::get_os()
    {
        // TODO: cache this object and return the cached version
        return std::make_shared<ds::pc::PCOS>();
    }
}