#pragma once

#include "Batch.h"
#include "GameObject.h"

#include <vector>
#include <memory>

#include <vector>

namespace OpenglToolKit
{
    class GameObjectManager
    {
        private:        
            static GameObjectManager* m_Instance;

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
            
            void Render();

            void AddGameObject(GameObject* go);
            void RemoveGameObject(GameObject* go);
            
    };    
} // namespace OpenglToolKit
