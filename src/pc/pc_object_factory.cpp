#include "pc_object_factory.h"
#include "pc_output_handler.h"
#include "pc_input_handler.h"
#include "pc_os.h"

namespace ds::pc
{
    std::shared_ptr<ds::OutputHandler> PCObjectFactory::_get_output_handler()
    {
        return std::make_shared<PCOutputHandler>();
    }

    std::shared_ptr<ds::InputHandler> PCObjectFactory::_get_input_handler()
    {
        return std::make_shared<PCInputHandler>();
    }

    std::shared_ptr<ds::OS> PCObjectFactory::_get_os()
    {
        return std::make_shared<ds::pc::PCOS>();
    }
}