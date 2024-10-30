#pragma once

#include <string>
#include <glm/vec2.hpp>

class Texture2D
{
public:
    explicit Texture2D(const std::string& filepath, bool transparency = true);
    void bind(int unit = 0) const;

    ~Texture2D() = default;
    unsigned int id{};
    [[nodiscard]] glm::ivec2 getSize() const;

private:
    int width{};
    int height{};
};
