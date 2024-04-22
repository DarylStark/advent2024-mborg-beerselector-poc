#ifndef __PLATFORM_OBJECT_FACTORY_H__
#define __PLATFORM_OBJECT_FACTORY_H__

#include <memory>
#include "output_handler.h"
#include "input_handler.h"
#include "os.h"

namespace ds
{
    class PlatformObjectFactory
    {
        // Interface for a Abstract Factory for platform specific objects.
    public:
        virtual std::shared_ptr<OutputHandler> get_output_handler() = 0;
        virtual std::shared_ptr<InputHandler> get_input_handler() = 0;

        virtual std::shared_ptr<OS> get_os() = 0;
    };
}

#endif /* __PLATFORM_OBJECT_FACTORY_H__ */