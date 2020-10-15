#include "Batch.h"
#include "Mesh.h"

namespace OpenglToolKit
{
    Batch::Batch(unsigned int maxNumVertices)
        :m_MaxNumVertices(maxNumVertices), m_NumUsedVertices(0)
    {
        m_VAO = std::make_unique<easyGL::VertexArray>();
        m_VB = std::make_unique<easyGL::VertexBuffer>(nullptr, 300 * sizeof(OpenglToolKit::VertexData), GL_DYNAMIC_DRAW); // allocate memory for 300 vertex
    }
    
    Batch::~Batch() { }

    bool Batch::isEmpty() const 
    {
        return (m_NumUsedVertices == 0);
    }
    bool Batch::isEnoughRoom(unsigned int numVertices)
    { 
        return ( m_NumUsedVertices + numVertices <= m_MaxNumVertices );
    }

    Batch* Batch::getFullest( Batch* pBatch ){
        return ( m_NumUsedVertices > pBatch->m_NumUsedVertices ? this : pBatch ); 
    }

    int Batch::getPriority() const{
        return m_Priority;
    }

    void Batch::AddVertices(const std::vector<OpenglToolKit::VertexData> &vertices)
    {
        // not implemented
    }
    void Batch::Render()
    {
        // not implemented
    }

} // namespace OpenglToolKit
