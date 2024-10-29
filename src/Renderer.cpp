#include "Renderer.h"

#include <glm/ext/matrix_transform.hpp>

Renderer::Renderer(const ShaderProgram& shaderProgram, const QuadMesh& quadMesh, const Window& window) :
    shaderProgram(shaderProgram), quadMesh(quadMesh), window(window)
{
}

void Renderer::drawTexture(const Texture2D& texture, const glm::vec2& pos, const glm::vec2& size,
                           const bool centered) const
{
    const glm::vec2 windowSize = window.getSize();

    glm::mat4 transform(1.0);
    transform = glm::scale(transform, glm::vec3(1.0f / windowSize.x, 1.0f / windowSize.y, 1.0f));
    transform = glm::translate(transform, glm::vec3(2.0f * (pos.x - windowSize.x * 0.5f),
                                                    2.0f * (-pos.y + windowSize.y * 0.5f), 0.0f));
    if (!centered)
        transform = glm::translate(transform, glm::vec3(size.x, -size.y, 0.0f));
    transform = glm::scale(transform, glm::vec3(size, 1.0f));

    shaderProgram.use();
    shaderProgram.setMat4("transform", transform);
    shaderProgram.setTexture("texture1", texture, 0);
    quadMesh.bind();
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr);
}
