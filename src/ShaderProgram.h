#pragma once
#include <string>
#include <glm/vec4.hpp>

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
    void setTexture(const std::string& name, unsigned int texture, int unit) const;

private:
    unsigned int id;

    static void checkCompileErrors(unsigned int shader, const std::string& type);
};



