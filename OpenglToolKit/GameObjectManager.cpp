#include "GameObjectManager.h"

#include "BatchManager.h"

#include "WorldManager.h"

#include <iostream>


namespace OpenglToolKit
{
    GameObjectManager* GameObjectManager::m_Instance = nullptr;

    float GameObjectManager::GetDistanceToCamera(const GameObject* go){
        glm::vec3 cameraPostion;
        glm::vec3 cameraOrientation;
        WorldManager::Instance()->GetCameraTransform(cameraPostion, cameraOrientation);

        float dist = -1;
        glm::mat4 transformMatrix = go->GetTransformMatrix();
        unsigned int numberOfVertex = go->m_Mesh.m_Vertices.size();
        for (int j = 0; j < numberOfVertex; j++){
            glm::vec3 verticePos = transformMatrix * glm::vec4(go->m_Mesh.m_Vertices[j].Position, 1.0f);
            if (dist < 0){
                dist = glm::length(verticePos - cameraPostion);
            }
            else{
                dist = std::min(dist, glm::length(verticePos - cameraPostion));
            }
        }
        return dist;
    }


    void GameObjectManager::Render() const{
        std::priority_queue<GameObject*, std::vector<GameObject*>, CompareGameObject> queue;
        for (int i = 0; i < m_GameObjects.size(); i++){
            queue.push(m_GameObjects[i]);
        }

        glm::vec3 cameraPostion;
        glm::vec3 cameraOrientation;
        WorldManager::Instance()->GetCameraTransform(cameraPostion, cameraOrientation);

        std::cout << std::endl << "Render" << std::endl;
        while (!queue.empty())
        {
            GameObject* go = queue.top();

            std::cout << "dst : " << GetDistanceToCamera(go) << std::endl;
            if (go->m_Active){
                glm::mat4 transformMatrix = go->m_Transform.GetTransformMatrix();
                unsigned int numberOfVertex = go->m_Mesh.m_Vertices.size();
                std::vector<OpenglToolKit::VertexData> vertices;
                for (int j = 0; j < numberOfVertex; j++){
                    vertices.push_back(go->m_Mesh.m_Vertices[j]); 
                    vertices[j].Position = transformMatrix * glm::vec4(vertices[j].Position, 1.0f);
                }
                BatchManager::Instance()->Render(vertices, go->m_Mesh.m_Triangles, go->m_Material);
            }
            queue.pop();
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
