#include "Texture2D.h"
#include <iostream>
#define STB_IMAGE_IMPLEMENTATION
#include <format>
#include <stb_image.h>
#include <glad/glad.h>

Texture2D::Texture2D(const std::string& filepath, const bool transparency)
{
    int nrChannels;
    stbi_set_flip_vertically_on_load(true);
    unsigned char* data = stbi_load(filepath.c_str(), &width, &height, &nrChannels, 0);
    if (data == nullptr)
    {
        auto failureReason = stbi_failure_reason();
        std::cout << std::format("ERROR: Could not load file at '{}' because: {}", filepath, failureReason) <<
            std::endl;
    }
    glGenTextures(1, &id);
    glBindTexture(GL_TEXTURE_2D, id);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST_MIPMAP_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

    const int format = transparency ? GL_RGBA : GL_RGB;
    glTexImage2D(GL_TEXTURE_2D, 0, format, width, height, 0, format, GL_UNSIGNED_BYTE, data);
    glGenerateMipmap(GL_TEXTURE_2D);
    stbi_image_free(data);
    std::cout << std::format("Loaded texture from '{}'", filepath) << std::endl;
    std::cout << std::format("Texture size: {}x{}", width, height) << std::endl;
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
