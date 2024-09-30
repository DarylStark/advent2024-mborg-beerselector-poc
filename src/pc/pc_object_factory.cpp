#include "pc_object_factory.h"

#include "pc_configuration_loader.h"
#include "pc_input_handler.h"
#include "pc_os.h"
#include "pc_output_handler.h"

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

    std::shared_ptr<ds::ConfigurationLoader>
    PCObjectFactory::_get_configuration_loader()
    {
        return std::make_shared<ds::pc::PCConfigurationLoader>();
    }
}  // namespace ds::pc