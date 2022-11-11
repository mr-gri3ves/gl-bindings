#include "Shader.h"

GLB::Shader::Shader(const std::string_view &filePath, Type type)
{
    std::ifstream ifs(filePath.data());

    if (!ifs.good())
    {
        throw EXCEPTION::BadShaderFileError("Invlalid shader file");
    }

    auto content = std::string((std::istreambuf_iterator<char>(ifs)), std::istreambuf_iterator<char>()).data();

    if (!ifs.eof())
    {
        throw EXCEPTION::BadShaderFileError("Invliad shader file");
    }

    id = glCreateShader(type == Type::VERTEX ? GL_VERTEX_SHADER : GL_FRAGMENT_SHADER);

    if(id == 0)
    {
        throw EXCEPTION::ShaderCreationError("Could not create shader");
    }

    glShaderSource(id, 1, &content, nullptr);
    glCompileShader(id);

    int success;

    glGetShaderiv(id, GL_COMPILE_STATUS, &success);

    if (!success)
    {
        int len;
        glGetShaderiv(id, GL_INFO_LOG_LENGTH, &len);
        if (len == 0)
        {
            glDeleteShader(id);
            id = 0;
            throw EXCEPTION::ShaderCompilationError("Could not compile shader");
        }
        std::vector<char> log(len);
        glGetShaderInfoLog(id, log.size(), &len, log.data());
        glDeleteShader(id);
        id = 0;
        throw EXCEPTION::ShaderCompilationError(log.data());
    }
}

GLuint GLB::Shader::getId() const
{
    return id;  
}

GLB::Shader::~Shader()
{
    glDeleteShader(id);
    id = 0;
}