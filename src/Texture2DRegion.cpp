#include "Texture2DRegion.h"

Texture2DRegion::Texture2DRegion(const Texture2D& texture): texture(texture), topLeft(0.0f, 0.0f), bottomRight(texture.getSize())
{
}

Texture2DRegion::Texture2DRegion(const Texture2D& texture, const glm::vec2& topLeft, const glm::vec2& bottomRight):
    texture(texture), topLeft(topLeft), bottomRight(bottomRight)
{
}
