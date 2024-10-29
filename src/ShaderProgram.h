#pragma once
#include <string>
#include <glm/vec4.hpp>
#include <glm/ext/matrix_float4x4.hpp>

#include "Texture2D.h"

class ShaderProgram
{
public:
    ShaderProgram(const std::string& vertexShaderPath, const std::string& fragmentShaderPath);
    ~ShaderProgram() = default;
    void use() const;

    void setBool(const std::string& name, bool value) const;
    void setInt(const std::string& name, int value) const;
    void setFloat(const std::string& name, float value) const;
    void setVec4(const std::string& name, glm::vec4& value) const;
    void setTexture(const std::string& name, const Texture2D& texture, int unit) const;
    void setMat4(const std::string& name, glm::mat4 mat) const;

private:
    unsigned int id;

    static void checkCompileErrors(unsigned int shader, const std::string& type);
};



