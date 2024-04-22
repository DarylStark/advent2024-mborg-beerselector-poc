#include "cached_platform_object_factory.h"

namespace ds
{
    std::shared_ptr<OutputHandler> CachedPlatformObjectFactory::get_output_handler()
    {
        if (!_output_handler)
            _output_handler = _get_output_handler();
        return _output_handler;
    }

    std::shared_ptr<InputHandler> CachedPlatformObjectFactory::get_input_handler()
    {
        if (!_input_handler)
            _input_handler = _get_input_handler();
        return _input_handler;
    }

    std::shared_ptr<OS> CachedPlatformObjectFactory::get_os()
    {
        if (!_os)
            _os = _get_os();
        return _os;
    }
}