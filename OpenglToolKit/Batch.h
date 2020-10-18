#pragma once

#include <vector>

#include "../easyGL/VertexArray.h"
#include "../easyGL/IndexBuffer.h"
#include "../easyGL/Shader.h"

#include "Mesh.h"
#include "Material.h"

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
            Material* m_Material = nullptr;
            std::unique_ptr<easyGL::IndexBuffer> m_IndexBuffer;
            
        public:
            Batch(unsigned int MaxNumVertices, unsigned int maxNumTriangles);
            ~Batch();

            bool isEmpty() const;
            bool isEnoughRoom(unsigned int numVertices, unsigned int numTriangles) const;
            Batch* getFullest(Batch* pBatch);
            int getPriority() const { return m_Priority; }

            Material* GetMaterial() const { return m_Material; }

            void AddData(std::vector<VertexData> &vertices, std::vector<unsigned int> &triangles);
            void AddData(std::vector<VertexData> &vertices, std::vector<unsigned int> &triangles, Material* mat);
            void Render();
    };    
} // namespace OpenglToolKit
