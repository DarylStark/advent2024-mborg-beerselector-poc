#ifndef __PC_CONFIGURATION_LOADER_H__
#define __PC_CONFIGURATION_LOADER_H__

#include "../ds/configuration_loader.h"

namespace ds::pc
{
    class PCConfigurationLoader : public ds::ConfigurationLoader
    {
    public:
        void load_configuration() override;
    };
}

#endif /* __PC_CONFIGURATION_LOADER_H__ */