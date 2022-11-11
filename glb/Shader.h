#ifndef GLB_SHADER_H
#define GLB_SHADER_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <string_view>
#include <fstream>
#include <vector>

#include "Exception.h"

namespace GLB 
{
    enum class Type 
    {
        VERTEX,
        FRAGMENT
    };

    struct Shader final
    {
    public:
        Shader(const std::string_view& filePath, Type type);
        GLuint getId() const;
        Type getShaderType() const;
        
        ~Shader();

    private:
        GLuint id;
    };
}

#endif //GLB_SHADER_H