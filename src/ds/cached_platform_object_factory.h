#ifndef __CACHE_PLATFORM_OBJECT_FACTORY_H__
#define __CACHE_PLATFORM_OBJECT_FACTORY_H__

#include <memory>
#include "platform_object_factory.h"

namespace ds
{
    class CachedPlatformObjectFactory : public PlatformObjectFactory
    {
    private:
        std::shared_ptr<OutputHandler> _output_handler;
        std::shared_ptr<InputHandler> _input_handler;
        std::shared_ptr<OS> _os;

    protected:
        virtual std::shared_ptr<OutputHandler> _get_output_handler() = 0;
        virtual std::shared_ptr<InputHandler> _get_input_handler() = 0;
        virtual std::shared_ptr<OS> _get_os() = 0;

    public:
        std::shared_ptr<OutputHandler> get_output_handler();
        std::shared_ptr<InputHandler> get_input_handler();
        std::shared_ptr<OS> get_os();
    };
};

#endif /* __CACHE_PLATFORM_OBJECT_FACTORY_H__ */