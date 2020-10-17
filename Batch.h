#pragma once

#include <vector>

#include "easyGL/VertexArray.h"
#include "easyGL/IndexBuffer.h"
#include "easyGL/Shader.h"

#include "Mesh.h"

#include <memory>

namespace OpenglToolKit
{
    class Batch
    {
        private:
            unsigned int m_MaxNumVertices;
            unsigned int m_NumUsedVertices;

            unsigned int m_MaxNumTriangles;
            unsigned int m_NumUsedTriangles;

            int m_Priority;

            std::unique_ptr<easyGL::VertexArray> m_VAO;
            std::unique_ptr<easyGL::VertexBuffer> m_VB;
            easyGL::Shader* m_Shader;
            std::unique_ptr<easyGL::IndexBuffer> m_IndexBuffer;
            
        public:
            Batch(unsigned int MaxNumVertices, unsigned int maxNumTriangles);
            ~Batch();

            bool isEmpty() const;
            bool isEnoughRoom(unsigned int numVertices, unsigned int numTriangles);
            Batch* getFullest(Batch* pBatch);
            int getPriority() const;

            void AddData(std::vector<VertexData> &vertices, std::vector<unsigned int> &triangles);
            void Render();
    };    
} // namespace OpenglToolKit
