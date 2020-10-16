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
        EmptyBatch(true, m_Batches[0].get());
    }

    // Render all the batchs
    void BatchManager::Render(){
        // not implemented
        std::cout << "Rendering :" << std::endl;
        for(std::unordered_map<GameObject*, GameObjectState>::iterator i = m_GameObjectsToRender.begin(); i!=m_GameObjectsToRender.end(); ++i) {
            std::cout << "State : " << (i->second).State << std::endl;
            std::cout << "Affected Batch : " << (i->second).AffectedBatch << std::endl;
            if ((i->second).State){
                std::cout << "  - Position : " << std::endl;
                std::cout << i->first->m_Transform.m_Position.x << ", ";
                std::cout << i->first->m_Transform.m_Position.y << ", ";
                std::cout << i->first->m_Transform.m_Position.z << std::endl;
                std::cout << "  - Rotation : " << std::endl;
                std::cout << i->first->m_Transform.m_Rotation.x << ", ";
                std::cout << i->first->m_Transform.m_Rotation.y << ", ";
                std::cout << i->first->m_Transform.m_Rotation.z << ", ";
                std::cout << i->first->m_Transform.m_Rotation.w << std::endl;
                std::cout << "  - Scale : " << std::endl;
                std::cout << i->first->m_Transform.m_Scale.x << ", ";
                std::cout << i->first->m_Transform.m_Scale.y << ", ";
                std::cout << i->first->m_Transform.m_Scale.z << std::endl;
                std::cout << std::endl;
            }
        }
    }

    // add or remove gameobject to the list of gameObject to render
    void BatchManager::SetGameObjectActive(GameObject* go, bool active){
        m_GameObjectsToRender[go] = GameObjectState(active, -1);
    }

    void BatchManager::DetroyGameObject(GameObject* go){
        if (m_GameObjectsToRender.find(go) != m_GameObjectsToRender.end())
        {
            m_GameObjectsToRender.erase(go);
        }
    }
} // namespace OpenglToolKit
