#pragma once
#include "QuadMesh.h"
#include "ShaderProgram.h"
#include "Texture2D.h"
#include "Texture2DRegion.h"
#include "Window.h"

class Renderer
{
public:
    Renderer(const ShaderProgram& shaderProgram, const QuadMesh& quadMesh, const Window& window);
    void drawTexture(const Texture2D& texture, const glm::vec2& pos, const glm::vec2& size, bool centered = true) const;
    void drawTextureRegion(const Texture2DRegion& texRegion, const glm::vec2& pos, const glm::vec2& size, bool centered = true) const;
    void drawTextureRegion(const Texture2DRegion& texRegion, const glm::vec2& pos, float scale = 1, bool centered = true) const;

private:
    ShaderProgram shaderProgram;
    QuadMesh quadMesh;
    Window window;
};
