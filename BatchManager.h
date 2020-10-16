#pragma once

#include "Batch.h"
#include "GameObject.h"

#include <vector>
#include <memory>

#include <unordered_map>

namespace OpenglToolKit
{
    class BatchManager
    {
        private:
            struct GameObjectState
            {
                bool State;
                int AffectedBatch;

                GameObjectState(bool active, int batchNum){
                    State = active;
                    AffectedBatch = batchNum;
                }
                
                GameObjectState(){
                    State = true;
                    AffectedBatch = -1;
                }
            };
        
            static BatchManager* m_Instance;

            std::unordered_map<GameObject*, GameObjectState> m_GameObjectsToRender;

            std::vector<std::shared_ptr<Batch>> m_Batches;
            unsigned m_MaxNumVerticesPerBatch;
            unsigned m_MaxNumTianglesPerBatch;
            unsigned m_NumBatches;

            BatchManager(){}
            ~BatchManager(){
                m_Batches.clear();

                if (m_Instance){
                    delete m_Instance;
                }
            }

            void EmptyBatch(bool emptyAll, Batch* BatchToEmpty); // not implemented

        public:
            static BatchManager* Instance()
            {
                if (!m_Instance){
                    m_Instance = new BatchManager();
                }
                return m_Instance;
            }

            static void Init(unsigned NumBatches, unsigned numVerticesPerBatch, unsigned numTrianglesPerBatch);

            void EmptyAll();
            void Render(); // not implemented

            void SetGameObjectActive(GameObject* go, bool active);
            void DetroyGameObject(GameObject* go);
            
    };    
} // namespace OpenglToolKit
