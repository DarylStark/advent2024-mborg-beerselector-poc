#ifndef __BASE_APPLICATION_H__
#define __BASE_APPLICATION_H__

#include <memory>
#include "application.h"
#include "platform_object_factory.h"
#include "./state.h"

namespace ds
{
    class BaseApplication : public Application
    {
    protected:
        // Object factory (platform specific)
        std::shared_ptr<PlatformObjectFactory> _factory;

        // State
        std::shared_ptr<ds::State> _state;

    public:
        BaseApplication(std::shared_ptr<PlatformObjectFactory> factory);

        // State methods
        void set_state(std::shared_ptr<ds::State> state);
    };
}

#endif /* __BASE_APPLICATION_H__ */