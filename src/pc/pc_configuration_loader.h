#ifndef PC_CONFIGURATION_LOADER_H
#define PC_CONFIGURATION_LOADER_H

#include "../ds/configuration_loader.h"

namespace ds::pc
{
    class PCConfigurationLoader : public ds::ConfigurationLoader
    {
    public:
        void load_configuration() override;
    };
}  // namespace ds::pc

#endif /* PC_CONFIGURATION_LOADER_H */