#include "BatchManager.h"

#include <iostream>
#include <queue>

namespace OpenglToolKit
{
    BatchManager* BatchManager::m_Instance = nullptr;
    int BatchManager::nbDrawCallPerframe = 0;

    void BatchManager::EmptyBatch(bool emptyAll, Batch* BatchToEmpty, std::vector<std::shared_ptr<Batch>> &BatchList){
        if (!emptyAll && BatchToEmpty->GetMaterial()->IsTransparent()){
            EmptyBatch(true, m_BatchesOpaque[0].get(), m_BatchesOpaque);
        }
        std::priority_queue<Batch*, std::vector<Batch*>, CompareBatch> queue;
        for (int i = 0; i < BatchList.size(); i++){
            if (!BatchList[i]->isEmpty()){
                if (emptyAll || (BatchList[i]->getPriority() < BatchToEmpty->getPriority()))
                {
                    queue.push(BatchList[i].get());
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

        Instance()->m_BatchesOpaque.reserve(NumBatches);
        for( unsigned u = 0; u < NumBatches; ++u ) 
        { 
            Instance()->m_BatchesOpaque.push_back(std::make_shared<Batch>(numVerticesPerBatch, numTrianglesPerBatch));
        }

        Instance()->m_BatchesTransparent.reserve(NumBatches);
        for( unsigned u = 0; u < NumBatches; ++u ) 
        { 
            Instance()->m_BatchesTransparent.push_back(std::make_shared<Batch>(numVerticesPerBatch, numTrianglesPerBatch));
        }
        Instance()->m_lastWasTransparent = false;
    }

    void BatchManager::EmptyAll(){
        EmptyBatch(true, m_BatchesOpaque[0].get(), m_BatchesOpaque);
        EmptyBatch(true, m_BatchesTransparent[0].get(), m_BatchesTransparent);
        std::cout << BatchManager::nbDrawCallPerframe << " Draw call for this frame" << std::endl;
        BatchManager::nbDrawCallPerframe = 0;
    }

    void BatchManager::Render(std::vector<OpenglToolKit::VertexData> vertices, std::vector<unsigned int> triangles, Material* mat, 
                                std::vector<std::shared_ptr<Batch>> &BatchList){
        Batch* emptyBatch = nullptr;
        Batch* fullestBatch = BatchList[0].get();

        for (int i = 0; i < BatchList.size(); i++){
            Batch* batch = BatchList[i].get();
            if (batch->GetMaterial() == mat) // same config
            {
                if (!batch->isEnoughRoom(vertices.size(), triangles.size()))
                {
                    EmptyBatch(false, batch, BatchList);
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

        EmptyBatch(false, fullestBatch, BatchList);
        fullestBatch->AddData(vertices, triangles, mat);
    }

    void BatchManager::Render(std::vector<OpenglToolKit::VertexData> vertices, std::vector<unsigned int> triangles, Material* mat){
        if (mat->IsTransparent()){
            Render(vertices, triangles, mat, m_BatchesTransparent);
            m_lastWasTransparent = true;
        }
        else{
            if (m_lastWasTransparent){
                EmptyBatch(true, m_BatchesOpaque[0].get(), m_BatchesOpaque);
                EmptyBatch(true, m_BatchesTransparent[0].get(), m_BatchesTransparent);
            }
            Render(vertices, triangles, mat, m_BatchesOpaque);
            m_lastWasTransparent = false;
        }
    }
} // namespace OpenglToolKit
