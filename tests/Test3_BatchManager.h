#pragma once

#include "Test.h"

#include "../GameObject.h"

#include "../easyGL/Renderer.h"
#include "../easyGL/VertexArray.h"
#include "../easyGL/VertexBufferLayout.h"
#include "../easyGL/Texture.h"

#include <memory>

namespace tests
{
    class Test3_BatchManager : public Test
    {
        private:
            OpenglToolKit::GameObject m_GameObject1;
            OpenglToolKit::GameObject m_GameObject2;
            
            bool m_active1;
            float m_Trans1[3];
            float m_Rot1[3];
            float m_Scale1[3];
            
            bool m_active2;
            float m_Trans2[3];
            float m_Rot2[3];
            float m_Scale2[3];

        public:
            Test3_BatchManager();
            ~Test3_BatchManager();

            void OnUpdate(float deltaTime) override;
            void OnRender() override;
            void OnImGuiRender() override;
    };
    
} // namespace tests