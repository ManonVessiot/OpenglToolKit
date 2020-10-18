#pragma once

#include "Batch.h"
#include "Material.h"

#include <vector>
#include <memory>
#include <functional>

namespace OpenglToolKit
{
    class BatchManager
    {
        private:
            static BatchManager* m_Instance;

            std::vector<std::shared_ptr<Batch>> m_BatchesOpaque;
            std::vector<std::shared_ptr<Batch>> m_BatchesTransparent;
            unsigned m_MaxNumVerticesPerBatch;
            unsigned m_MaxNumTianglesPerBatch;
            unsigned m_NumBatches;

            bool m_lastWasTransparent;

            BatchManager(){}
            ~BatchManager(){
                m_BatchesOpaque.clear();
                m_BatchesTransparent.clear();

                if (m_Instance){
                    delete m_Instance;
                }
            }

            struct CompareBatch : public std::binary_function<const Batch*, const Batch*, bool>
            { 
                bool operator()( const Batch* batchA, const Batch* batchB ) const 
                { 
                    return ( batchA->getPriority() > batchB->getPriority() ); 
                }
            };

            void EmptyBatch(bool emptyAll, Batch* BatchToEmpty, std::vector<std::shared_ptr<Batch>> &BatchList);
            void Render(std::vector<OpenglToolKit::VertexData> vertices, std::vector<unsigned int> triangles, Material* mat, 
                            std::vector<std::shared_ptr<Batch>> &BatchList);

        public:
            static int nbDrawCallPerframe;
            
            static BatchManager* Instance()
            {
                if (!m_Instance){
                    m_Instance = new BatchManager();
                }
                return m_Instance;
            }

            static void Init(unsigned NumBatches, unsigned numVerticesPerBatch, unsigned numTrianglesPerBatch);

            void EmptyAll();
            void Render(std::vector<OpenglToolKit::VertexData> vertices, std::vector<unsigned int> triangles, Material* mat);
            
    };    
} // namespace OpenglToolKit
