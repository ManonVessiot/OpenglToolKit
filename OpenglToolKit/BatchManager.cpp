#include "BatchManager.h"

#include <iostream>
#include <queue>

namespace OpenglToolKit
{
    BatchManager* BatchManager::m_Instance = nullptr;
    int BatchManager::nbDrawCallPerframe = 0;

    void BatchManager::EmptyBatch(bool emptyAll, Batch* BatchToEmpty){
        std::priority_queue<Batch*, std::vector<Batch*>, CompareBatch> queue;
        for (int i = 0; i < m_NumBatches; i++){
            if (!m_Batches[i]->isEmpty()){
                if (emptyAll || (m_Batches[i]->getPriority() < BatchToEmpty->getPriority()))
                {
                    queue.push(m_Batches[i].get());
                }                
            }
        }

        while (!queue.empty())
        {
            Batch* batch = queue.top();
            batch->Render();
            queue.pop();
        }

        if (!emptyAll){
            BatchToEmpty->Render();
        }        
    }

    void BatchManager::Init(unsigned NumBatches, unsigned numVerticesPerBatch, unsigned numTrianglesPerBatch){
        Instance()->m_NumBatches = NumBatches;
        Instance()->m_MaxNumVerticesPerBatch = numVerticesPerBatch;
        Instance()->m_MaxNumTianglesPerBatch = numTrianglesPerBatch;

        Instance()->m_Batches.reserve(NumBatches);
        for( unsigned u = 0; u < NumBatches; ++u ) 
        { 
            Instance()->m_Batches.push_back(std::make_shared<Batch>(numVerticesPerBatch, numTrianglesPerBatch));
        }
    }

    void BatchManager::EmptyAll(){
        EmptyBatch(true, m_Batches[0].get());
        std::cout << std::endl << BatchManager::nbDrawCallPerframe << " Draw call for this frame" << std::endl << std::endl;
        BatchManager::nbDrawCallPerframe = 0;
    }

    void BatchManager::Render(std::vector<OpenglToolKit::VertexData> vertices, std::vector<unsigned int> triangles, Material* mat){
        Batch* emptyBatch = nullptr;
        Batch* fullestBatch = m_Batches[0].get();

        for (int i = 0; i < m_NumBatches; i++){
            Batch* batch = m_Batches[i].get();
            if (batch->GetMaterial() == mat) // same config
            {
                if (!batch->isEnoughRoom(vertices.size(), triangles.size()))
                {
                    EmptyBatch(false, batch);
                }
                batch->AddData(vertices, triangles);
                return;
            }

            if (emptyBatch == nullptr && batch->isEmpty())
            {
                emptyBatch = batch;
            }

            fullestBatch = batch->getFullest(fullestBatch);
        }

        if (emptyBatch != nullptr)
        {
            emptyBatch->AddData(vertices, triangles, mat);
            return;
        }

        EmptyBatch(false, fullestBatch);
        fullestBatch->AddData(vertices, triangles, mat);
    }
} // namespace OpenglToolKit
