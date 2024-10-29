#pragma once
#include "QuadMesh.h"
#include "ShaderProgram.h"
#include "Texture2D.h"
#include "Window.h"

class Renderer
{
public:
    Renderer(const ShaderProgram& shaderProgram, const QuadMesh& quadMesh, const Window& window);
    void drawTexture(const Texture2D& texture, const glm::vec2& pos, const glm::vec2& size, bool centered = true) const;

private:
    ShaderProgram shaderProgram;
    QuadMesh quadMesh;
    Window window;
};
