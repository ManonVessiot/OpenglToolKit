#include "MeshBuilder.h"

namespace OpenglToolKit
{
    MeshBuilder* MeshBuilder::m_Instance = nullptr;

    void MeshBuilder::CreateQuad(Mesh &mesh, float size) const
    {
        float halfSize = size / 2.0f;
        mesh.Clear();
        mesh.AddVertex(glm::vec3(-halfSize, -halfSize, 0.0f), glm::vec3(0.0f, 0.0f, 1.0f), glm::vec4(0.0f), glm::vec2(0.0f, 0.0f), glm::vec4(1.0f));
        mesh.AddVertex(glm::vec3( halfSize, -halfSize, 0.0f), glm::vec3(0.0f, 0.0f, 1.0f), glm::vec4(0.0f), glm::vec2(1.0f, 0.0f), glm::vec4(1.0f));
        mesh.AddVertex(glm::vec3( halfSize,  halfSize, 0.0f), glm::vec3(0.0f, 0.0f, 1.0f), glm::vec4(0.0f), glm::vec2(1.0f, 1.0f), glm::vec4(1.0f));
        mesh.AddVertex(glm::vec3(-halfSize,  halfSize, 0.0f), glm::vec3(0.0f, 0.0f, 1.0f), glm::vec4(0.0f), glm::vec2(0.0f, 1.0f), glm::vec4(1.0f));

        mesh.AddTriangle(0, 1, 2);
        mesh.AddTriangle(2, 3, 0);
    }

    void MeshBuilder::CreateCube(Mesh &mesh, float size) const
    {
        float halfSize = size / 2.0f;
        mesh.Clear();
        mesh.AddVertex(glm::vec3(-halfSize, -halfSize,  halfSize), glm::vec3(-1.0f, -1.0f,  1.0f), glm::vec4(0.0f), glm::vec2(0.0f, 0.0f), glm::vec4(1.0f));
        mesh.AddVertex(glm::vec3( halfSize, -halfSize,  halfSize), glm::vec3( 1.0f, -1.0f,  1.0f), glm::vec4(0.0f), glm::vec2(1.0f, 0.0f), glm::vec4(1.0f));
        mesh.AddVertex(glm::vec3( halfSize,  halfSize,  halfSize), glm::vec3( 1.0f,  1.0f,  1.0f), glm::vec4(0.0f), glm::vec2(1.0f, 1.0f), glm::vec4(1.0f));
        mesh.AddVertex(glm::vec3(-halfSize,  halfSize,  halfSize), glm::vec3(-1.0f,  1.0f,  1.0f), glm::vec4(0.0f), glm::vec2(0.0f, 1.0f), glm::vec4(1.0f));

        mesh.AddVertex(glm::vec3(-halfSize, -halfSize, -halfSize), glm::vec3(-1.0f, -1.0f, -1.0f), glm::vec4(0.0f), glm::vec2(0.0f, 0.0f), glm::vec4(1.0f));
        mesh.AddVertex(glm::vec3(-halfSize,  halfSize, -halfSize), glm::vec3(-1.0f,  1.0f, -1.0f), glm::vec4(0.0f), glm::vec2(1.0f, 0.0f), glm::vec4(1.0f));
        mesh.AddVertex(glm::vec3( halfSize,  halfSize, -halfSize), glm::vec3( 1.0f,  1.0f, -1.0f), glm::vec4(0.0f), glm::vec2(1.0f, 1.0f), glm::vec4(1.0f));
        mesh.AddVertex(glm::vec3( halfSize, -halfSize, -halfSize), glm::vec3( 1.0f, -1.0f, -1.0f), glm::vec4(0.0f), glm::vec2(0.0f, 1.0f), glm::vec4(1.0f));

        mesh.AddTriangle(0, 1, 2);
        mesh.AddTriangle(2, 3, 0);

        mesh.AddTriangle(4, 5, 6);
        mesh.AddTriangle(6, 7, 4);

        mesh.AddTriangle(1, 7, 6);
        mesh.AddTriangle(6, 2, 1);

        mesh.AddTriangle(0, 3, 5);
        mesh.AddTriangle(5, 4, 0);

        mesh.AddTriangle(3, 2, 6);
        mesh.AddTriangle(6, 5, 3);

        mesh.AddTriangle(0, 4, 7);
        mesh.AddTriangle(7, 1, 0);
    }

} // namespace OpenglToolKit