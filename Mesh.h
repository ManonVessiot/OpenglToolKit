#pragma once

#include <glm/glm.hpp>

#include <vector>

namespace OpenglToolKit
{
    struct VertexData
    {
        glm::vec3 Position;
        glm::vec3 Normal;
        glm::vec4 Tangent;
        glm::vec2 UV;
        glm::vec4 Color;

        VertexData(glm::vec3 position, glm::vec3 normal, glm::vec4 tangent, glm::vec2 uv, glm::vec4 color){
            Position = position;
            Normal = normal;
            Tangent = tangent;
            UV = uv;
            Color = color;
        }
    };

    class Mesh
    {
        private:
        
        public:
            std::vector<VertexData> m_Vertices;
            std::vector<unsigned int> m_Triangles;
            
            Mesh(){}
            ~Mesh(){}

            void AddVertex(glm::vec3 position, glm::vec3 normal, glm::vec4 tangent, glm::vec2 uv, glm::vec4 color);
            void AddTriangle(unsigned int a, unsigned int b, unsigned int c);

            void Clear();
        };    
} // namespace OpenglToolKit

/*
1. Building a mesh from scratch:
    a) Assign vertices
    b) Assign triangles.

2. Modifying vertex attributes every frame:
    a) Get vertices
    b) Modify them
    c) Assign them back to the mesh.

3. Continously changing the mesh triangles and vertices:
    a) Call Clear to start fresh
    b) Assign vertices and other attributes
    c) Assign triangle indices.
*/