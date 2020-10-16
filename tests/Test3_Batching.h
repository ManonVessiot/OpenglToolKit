#pragma once

#include "Test.h"

#include "../GameObject.h"
#include "../Mesh.h"
#include "../Batch.h"

#include "../easyGL/Renderer.h"
#include "../easyGL/VertexArray.h"
#include "../easyGL/VertexBufferLayout.h"
#include "../easyGL/Texture.h"

#include <memory>

namespace tests
{
    class Test3_Batching : public Test
    {
        private:
            OpenglToolKit::GameObject m_GameObject;
            std::unique_ptr<OpenglToolKit::Batch> m_Batch;
            
            float m_Trans1[3];
            float m_Rot1[3];
            float m_Scale1[3];
            
            float m_Trans2[3];
            float m_Rot2[3];
            float m_Scale2[3];

        public:
            Test3_Batching();
            ~Test3_Batching();

            void OnUpdate(float deltaTime) override;
            void OnRender() override;
            void OnImGuiRender() override;
    };
    
} // namespace tests