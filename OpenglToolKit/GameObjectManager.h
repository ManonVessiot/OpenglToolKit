#pragma once

#include "Batch.h"
#include "GameObject.h"

#include <vector>
#include <memory>

#include <queue>

namespace OpenglToolKit
{
    class GameObjectManager
    {
        private:
            static GameObjectManager* m_Instance;

            static float GetDistanceToCamera(const GameObject* go);

            struct CompareGameObject : public std::binary_function<const GameObject*, const GameObject*, bool>
            { 
                bool operator()( const GameObject* goA, const GameObject* goB ) const 
                {
                    return ( GetDistanceToCamera(goA) > GetDistanceToCamera(goB) );
                    //return (goA->m_Mesh.m_Vertices.size() > goB->m_Mesh.m_Vertices.size() );
                }
            };
            std::vector<GameObject*> m_GameObjects;

            GameObjectManager(){}
            ~GameObjectManager(){
                if (m_Instance){
                    delete m_Instance;
                }
            }

        public:
            static GameObjectManager* Instance()
            {
                if (!m_Instance){
                    m_Instance = new GameObjectManager();
                }
                return m_Instance;
            }
            
            void Render() const;

            void AddGameObject(GameObject* go);
            void RemoveGameObject(GameObject* go);
            
    };    
} // namespace OpenglToolKit
