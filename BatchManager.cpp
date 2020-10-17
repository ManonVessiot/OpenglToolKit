#include "BatchManager.h"

#include <iostream>

namespace OpenglToolKit
{
    BatchManager* BatchManager::m_Instance = nullptr;

    void BatchManager::EmptyBatch(bool emptyAll, Batch* BatchToEmpty){
        // not implemented
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
        std::cout << "EmptyAll" << std::endl;
        EmptyBatch(true, m_Batches[0].get());
    }

    // Render all the batchs
    void BatchManager::Render(std::vector<OpenglToolKit::VertexData> vertices, std::vector<unsigned int> triangles){
        // not implemented
        std::cout << "Rendering :" << vertices.size() << "vertices and " << triangles.size() << " triangles" << std::endl;
    }
} // namespace OpenglToolKit
