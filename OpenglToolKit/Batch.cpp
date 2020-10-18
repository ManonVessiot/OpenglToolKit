#include "Batch.h"

#include <iostream>

#include "../easyGL/Renderer.h"
#include "BatchManager.h"

namespace OpenglToolKit
{
    Batch::Batch(unsigned int maxNumVertices, unsigned int maxNumTriangles)
        :m_MaxNumVertices(maxNumVertices), m_NumUsedVertices(0), m_MaxNumTriangles(maxNumTriangles), m_NumUsedTriangles(0),
        m_Priority(0)
    {        
        m_VAO = std::make_unique<easyGL::VertexArray>();
        m_VB = std::make_unique<easyGL::VertexBuffer>(nullptr, m_MaxNumVertices * sizeof(VertexData), GL_DYNAMIC_DRAW); // allocate memory for m_MaxNumVertices vertex
        
        easyGL::VertexBufferLayout layout;
        layout.Push(GL_FLOAT, 3);
        layout.Push(GL_FLOAT, 3);
        layout.Push(GL_FLOAT, 4);
        layout.Push(GL_FLOAT, 2);
        layout.Push(GL_FLOAT, 4);

        m_VAO->AddBuffer(*m_VB, layout);        
        
        m_IndexBuffer = std::make_unique<easyGL::IndexBuffer>(nullptr, m_MaxNumTriangles * 3, GL_DYNAMIC_DRAW); // allocate memory for m_MaxNumTriangles triangles
    }
    
    Batch::~Batch() { }

    bool Batch::isEmpty() const 
    {
        return (m_NumUsedVertices == 0);
    }
    bool Batch::isEnoughRoom(unsigned int numVertices, unsigned int numTriangles)
    { 
        return ( m_NumUsedVertices + numVertices <= m_MaxNumVertices && m_NumUsedTriangles + numTriangles <= m_MaxNumTriangles);
    }

    Batch* Batch::getFullest( Batch* pBatch ){
        return ( m_NumUsedVertices > pBatch->m_NumUsedVertices ? this : pBatch ); 
    }

    int Batch::getPriority() const{
        return m_Priority;
    }

    void Batch::AddData(std::vector<VertexData> &vertices, std::vector<unsigned int> &triangles, Material* mat){
        m_Material = mat;
        AddData(vertices, triangles);
    }

    void Batch::AddData(std::vector<VertexData> &vertices, std::vector<unsigned int> &triangles)
    {
        if (!isEnoughRoom(vertices.size(), triangles.size()))
        {
            std::cout << "Not enough size !" << std::endl;
            return;
        }
        if (vertices.empty())
        {
            std::cout << "vertices empty !" << std::endl;
            return;
        }

        // add vertices
        m_VAO->Bind();
        m_VB->Bind();

        m_VB->WriteData(m_NumUsedVertices * sizeof(VertexData), vertices.size() * sizeof(VertexData), vertices.data());


        for (int i = 0; i < triangles.size(); i++){
            triangles[i] += m_NumUsedVertices;
        }
        m_IndexBuffer->WriteData(m_NumUsedTriangles, triangles.size(), triangles.data());
        m_NumUsedVertices += vertices.size();
        m_NumUsedTriangles += triangles.size();
    }

    void Batch::Render()
    {
        if (m_NumUsedVertices == 0 || m_NumUsedTriangles == 0)
        {
            std::cout << "No vertices/triangles to render !" << std::endl;
            return;
        }
        if (m_Material->IsTransparent())
        {
            easyGL::Renderer::Depth(false);
            easyGL::Renderer::Blend(true);
        }
        else
        {
            easyGL::Renderer::Blend(false);
            easyGL::Renderer::Depth(true);
        }
        
        
        // Define Uniforms
        m_Material->Bind();
        // Draw
        easyGL::Renderer::Draw(*m_VAO, *m_IndexBuffer, *(m_Material->GetShader()));
        BatchManager::nbDrawCallPerframe += 1;
        // Clear Batch
        m_NumUsedVertices = 0;
        m_NumUsedTriangles = 0;
        
    }

} // namespace OpenglToolKit
