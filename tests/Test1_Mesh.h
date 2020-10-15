#pragma once

#include "Test.h"

#include "../Mesh.h"

#include "../easyGL/Renderer.h"
#include "../easyGL/VertexArray.h"
#include "../easyGL/VertexBufferLayout.h"
#include "../easyGL/Texture.h"

#include <memory>

namespace tests
{
    class Test1_Mesh : public Test
    {
        private:
            OpenglToolKit::Mesh m_Mesh;
            
            std::unique_ptr<easyGL::VertexArray> m_VAO; 
            std::unique_ptr<easyGL::IndexBuffer> m_IndexBuffer;
            std::unique_ptr<easyGL::Shader> m_Shader;
            std::unique_ptr<easyGL::VertexBuffer> m_VB;

        public:
            Test1_Mesh();
            ~Test1_Mesh();

            void OnUpdate(float deltaTime) override;
            void OnRender() override;
            void OnImGuiRender() override;
    };
    
} // namespace tests