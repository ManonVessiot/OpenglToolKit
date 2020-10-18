#include "GameObjectManager.h"

#include "BatchManager.h"

#include <iostream>


namespace OpenglToolKit
{
    GameObjectManager* GameObjectManager::m_Instance = nullptr;

    void GameObjectManager::Render(){
        for (int i = 0; i < m_GameObjects.size(); i++){
            if (m_GameObjects[i]->m_Active){
                glm::mat4 transformMatrix = m_GameObjects[i]->m_Transform.GetTransformMatrix();
                unsigned int numberOfVertex = m_GameObjects[i]->m_Mesh.m_Vertices.size();
                std::vector<OpenglToolKit::VertexData> vertices;
                for (int j = 0; j < numberOfVertex; j++){
                    vertices.push_back(m_GameObjects[i]->m_Mesh.m_Vertices[j]); 
                    vertices[j].Position = transformMatrix * glm::vec4(vertices[j].Position, 1.0f); 
                }
                BatchManager::Instance()->Render(vertices, m_GameObjects[i]->m_Mesh.m_Triangles);
            }
        }
    }

    void GameObjectManager::AddGameObject(GameObject* go){
        m_GameObjects.push_back(go);
    }

    void GameObjectManager::RemoveGameObject(GameObject* go){
        int i = 0;
        bool found = false;
        while (i < m_GameObjects.size() && !found)
        {
            if (m_GameObjects[i] == go)
            {
                m_GameObjects.erase(m_GameObjects.begin()+i);
            }
            i++;
        }
    }
} // namespace OpenglToolKit
