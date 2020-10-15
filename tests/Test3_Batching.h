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
    class Test3_Batching : public Test
    {
        private:
            OpenglToolKit::GameObject m_GameObject;
            
            float m_Trans[3];
            float m_Rot[3];
            float m_Scale[3];
            
            std::unique_ptr<easyGL::VertexArray> m_VAO; 
            std::unique_ptr<easyGL::IndexBuffer> m_IndexBuffer;
            std::unique_ptr<easyGL::Shader> m_Shader;
            std::unique_ptr<easyGL::VertexBuffer> m_VB;

        public:
            Test3_Batching();
            ~Test3_Batching();

            void OnUpdate(float deltaTime) override;
            void OnRender() override;
            void OnImGuiRender() override;
    };
    
} // namespace tests