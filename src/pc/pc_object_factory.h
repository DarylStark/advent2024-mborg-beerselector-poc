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
    public:
        std::shared_ptr<ds::OutputHandler> get_output_handler();
        std::shared_ptr<ds::InputHandler> get_input_handler();
        std::shared_ptr<ds::OS> get_os();
    };
}

#endif /* __PC_OBJECT_FACTORY_H__ */