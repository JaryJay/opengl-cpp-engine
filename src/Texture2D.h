#pragma once

#include <string>


class Texture2D
{
public:
    explicit Texture2D(const std::string& filepath, bool generateMipmaps = true);
    void bind(int unit = 0) const;

    ~Texture2D() = default;
    unsigned int id{};

private:
    int width{};
    int height{};
};
