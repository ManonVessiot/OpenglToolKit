#pragma once

#include <glm/glm.hpp>

#include <vector>

namespace OpenglToolKit
{
    class Mesh
    {
        private:
        
        public:
            static const unsigned int m_MaxSizeOfVertex = 16 * sizeof(float);

            std::vector<glm::vec3> m_VertexPosition;
            std::vector<glm::vec3> m_VertexNormal;
            std::vector<glm::vec4> m_VertexTangent;
            std::vector<glm::vec2> m_VertexUV;
            std::vector<glm::vec4> m_VertexColor;
            std::vector<unsigned int> m_Triangles;
            
            Mesh(){}
            ~Mesh(){}

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