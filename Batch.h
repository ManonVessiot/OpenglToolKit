#pragma once

#include <vector>

#include "easyGL/VertexArray.h"

#include <memory>

namespace OpenglToolKit
{
    class Batch
    {
        private:
            unsigned int m_MaxNumVertices;
            unsigned int m_NumUsedVertices;
            int m_Priority;

            std::unique_ptr<easyGL::VertexArray> m_VAO;
            std::unique_ptr<easyGL::VertexBuffer> m_VB;
            
        public:
            Batch(unsigned int MaxNumVertices); // not implemented
            ~Batch(); // not implemented

            bool isEmpty() const;
            bool isEnoughRoom(unsigned int numVertices);
            Batch* getFullest( Batch* pBatch );
            int getPriority() const;

            void AddVertices(const std::vector<OpenglToolKit::VertexData> &vertices); // not implemented
            void Render(); // not implemented
    };    
} // namespace OpenglToolKit
