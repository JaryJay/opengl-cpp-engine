#pragma once

class QuadMesh
{
public:
    QuadMesh();
    ~QuadMesh() = default;

    void bind() const;

private:
    unsigned int vbo{};
    unsigned int vao{};
    unsigned int ebo{};
};
