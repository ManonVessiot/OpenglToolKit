#include "Mesh.h"

namespace OpenglToolKit
{
    void Mesh::Clear(){
        m_Vertices.clear();
    }

    void Mesh::AddVertex(glm::vec3 position, glm::vec3 normal, glm::vec4 tangent, glm::vec2 uv, glm::vec4 color){
        m_Vertices.push_back(VertexData(position, normal, tangent, uv, color));
    }
    
    void Mesh::AddTriangle(unsigned int a, unsigned int b, unsigned int c){
        m_Triangles.push_back(a);
        m_Triangles.push_back(b);
        m_Triangles.push_back(c);
    }
} // namespace OpenglToolKit
