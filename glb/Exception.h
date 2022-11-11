#ifndef GLB_EXCEPTION_H
#define GLB_EXCEPTION_H

#include <stdexcept>

namespace GLB::EXCEPTION
{
    struct BadShaderFileError : std::runtime_error
    {
        BadShaderFileError(const char *msg) : std::runtime_error(msg) {}
    };

    struct ShaderCreationError : std::runtime_error 
    {
        ShaderCreationError(const char* msg) : std::runtime_error(msg) {}
    };

    struct ShaderCompilationError : std::runtime_error
    {
        ShaderCompilationError(const char *msg) : std::runtime_error(msg) {}
    };
}

#endif // GLB_EXCEPTION_H