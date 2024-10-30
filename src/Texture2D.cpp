#include "Texture2D.h"
#include <iostream>
#define STB_IMAGE_IMPLEMENTATION
#include <format>
#include <stb_image.h>
#include <glad/glad.h>

Texture2D::Texture2D(const std::string& filepath, const bool generateMipmaps)
{
    int nrChannels;
    unsigned char* data = stbi_load(filepath.c_str(), &width, &height, &nrChannels, 0);
    if (data == nullptr)
    {
        auto failureReason = stbi_failure_reason();
        std::cout << std::format("ERROR: Could not load file at '{}' because: {}", filepath, failureReason) <<
            std::endl;
    }
    glGenTextures(1, &id);
    glBindTexture(GL_TEXTURE_2D, id);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
    if (generateMipmaps)
        glGenerateMipmap(GL_TEXTURE_2D);
    stbi_image_free(data);
}

void Texture2D::bind(const int unit) const
{
    glActiveTexture(GL_TEXTURE0 + unit);
    glBindTexture(GL_TEXTURE_2D, id);
}

glm::ivec2 Texture2D::getSize() const
{
    return {width, height};
}
