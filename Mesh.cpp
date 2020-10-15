#include "Mesh.h"

namespace OpenglToolKit
{
    void Mesh::Clear(){
        m_VertexPosition.clear();
        m_VertexNormal.clear();
        m_VertexTangent.clear();
        m_VertexUV.clear();
        m_VertexColor.clear();
        m_Triangles.clear();
    }
} // namespace OpenglToolKit
