#ifndef __PC_OBJECT_FACTORY_H__
#define __PC_OBJECT_FACTORY_H__

#include <memory>

#include "../ds/platform_object_factory.h"

namespace ds::pc
{
    class PCObjectFactory : public ds::PlatformObjectFactory
    {
        // A generic PlatformOjbectFactory class that can be customized by using
        // templates.
    protected:
        std::shared_ptr<ds::OutputHandler> _get_output_handler();
        std::shared_ptr<ds::InputHandler> _get_input_handler();
        std::shared_ptr<ds::OS> _get_os();
        std::shared_ptr<ds::ConfigurationLoader> _get_configuration_loader();
    };
}  // namespace ds::pc

#endif /* __PC_OBJECT_FACTORY_H__ */