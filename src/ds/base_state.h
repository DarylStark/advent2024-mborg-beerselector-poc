#ifndef __BASE_STATE_H__
#define __BASE_STATE_H__

#include "platform_object_factory.h"
#include "state.h"
#include "base_application.h"

namespace ds
{
    class BaseState : public ds::State
    {
    protected:
        std::shared_ptr<ds::PlatformObjectFactory> _factory;
        ds::BaseApplication &_application;

    public:
        BaseState(std::shared_ptr<ds::PlatformObjectFactory> factory, ds::BaseApplication &application);
    };
}

#endif /* __BASE_STATE_H__ */