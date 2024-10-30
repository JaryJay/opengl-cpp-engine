#pragma once
#include "Texture2D.h"

class Texture2DRegion
{
public:
    explicit Texture2DRegion(const Texture2D& texture);
    Texture2DRegion(const Texture2D& texture, const glm::vec2& topLeft, const glm::vec2& bottomRight);

    const Texture2D& texture;
    glm::vec2 topLeft;
    glm::vec2 bottomRight;
};
