#include "Test2_MeshTransform.h"

#include "../easyGL/Renderer.h"

#include "../vendor/imgui/imgui.h"

namespace tests {
    Test2_MeshTransform::Test2_MeshTransform()
        :m_Trans{0.0f, 0.0f, 0.0f},
         m_Rot{0.0f, 0.0f, 0.0f},
         m_Scale{1.0f, 1.0f, 1.0f}
    {

        easyGL::Renderer::Blend();
        
        m_Shader = std::make_unique<easyGL::Shader>("shaders/BasicColor.shader");
        m_VAO = std::make_unique<easyGL::VertexArray>();
        m_VB = std::make_unique<easyGL::VertexBuffer>(nullptr, sizeof(OpenglToolKit::Mesh::m_MaxSizeOfVertex) * 300, GL_DYNAMIC_DRAW); // allocate memory for 300 vertex

        easyGL::VertexBufferLayout layout;
        layout.Push(GL_FLOAT, 3);
        layout.Push(GL_FLOAT, 3);
        layout.Push(GL_FLOAT, 4);
        layout.Push(GL_FLOAT, 2);
        layout.Push(GL_FLOAT, 4);

        m_VAO->AddBuffer(*m_VB, layout);

        m_IndexBuffer = std::make_unique<easyGL::IndexBuffer>(nullptr, 100 * 3, GL_DYNAMIC_DRAW); // allocate memory for 100 triangles
        
        m_Shader->Bind();

        m_Mesh.Clear();
        m_Mesh.m_VertexPosition.push_back(glm::vec3(-0.5f, -0.5f, 0.0f));
        m_Mesh.m_VertexPosition.push_back(glm::vec3( 0.5f, -0.5f, 0.0f));
        m_Mesh.m_VertexPosition.push_back(glm::vec3( 0.5f,  0.5f, 0.0f));
        m_Mesh.m_VertexPosition.push_back(glm::vec3(-0.5f,  0.5f, 0.0f));

        m_Mesh.m_VertexNormal.push_back(glm::vec3(0.0f, 0.0f, 1.0f));
        m_Mesh.m_VertexNormal.push_back(glm::vec3(0.0f, 0.0f, 1.0f));
        m_Mesh.m_VertexNormal.push_back(glm::vec3(0.0f, 0.0f, 1.0f));
        m_Mesh.m_VertexNormal.push_back(glm::vec3(0.0f, 0.0f, 1.0f));

        m_Mesh.m_VertexUV.push_back(glm::vec2(0.0f, 0.0f));
        m_Mesh.m_VertexUV.push_back(glm::vec2(1.0f, 0.0f));
        m_Mesh.m_VertexUV.push_back(glm::vec2(1.0f, 1.0f));
        m_Mesh.m_VertexUV.push_back(glm::vec2(0.0f, 1.0f));

        m_Mesh.m_Triangles.push_back(0); m_Mesh.m_Triangles.push_back(1); m_Mesh.m_Triangles.push_back(2);
        m_Mesh.m_Triangles.push_back(2); m_Mesh.m_Triangles.push_back(3); m_Mesh.m_Triangles.push_back(0);
    }

    Test2_MeshTransform::~Test2_MeshTransform()
    {
    }

    void Test2_MeshTransform::OnUpdate(float deltaTime)
    {
        m_MeshTransform.m_Position = glm::vec3(m_Trans[0], m_Trans[1], m_Trans[2]);
        m_MeshTransform.m_Rotation = glm::quat(glm::vec3(glm::radians(m_Rot[0]), glm::radians(m_Rot[1]), glm::radians(m_Rot[2])));
        m_MeshTransform.m_Scale = glm::vec3(m_Scale[0], m_Scale[1], m_Scale[2]);
        glm::mat4 transformMatrix = m_MeshTransform.GetTransformMatrix();

        unsigned int numberOfVertex = m_Mesh.m_VertexPosition.size();

        bool normal = m_Mesh.m_VertexNormal.size() == numberOfVertex;
        bool tangent = m_Mesh.m_VertexTangent.size() == numberOfVertex;
        bool uv = m_Mesh.m_VertexUV.size() == numberOfVertex;
        bool color = m_Mesh.m_VertexColor.size() == numberOfVertex;

        std::vector<float> vertices;
        for (int i = 0; i < numberOfVertex; i++){
            glm::vec3 pos = transformMatrix * glm::vec4(m_Mesh.m_VertexPosition[i], 1.0f);
            vertices.push_back(pos[0]);
            vertices.push_back(pos[1]);
            vertices.push_back(pos[2]);

            if (normal){
                glm::vec3 norm = m_Mesh.m_VertexNormal[i];
                vertices.push_back(norm[0]);
                vertices.push_back(norm[1]);
                vertices.push_back(norm[2]);
            }
            else
            {
                vertices.push_back(0.0f);
                vertices.push_back(0.0f);
                vertices.push_back(0.0f);
            }

            if (tangent){
                glm::vec4 tang = m_Mesh.m_VertexTangent[i];
                vertices.push_back(tang[0]);
                vertices.push_back(tang[1]);
                vertices.push_back(tang[2]);
                vertices.push_back(tang[3]);
            }
            else
            {
                vertices.push_back(0.0f);
                vertices.push_back(0.0f);
                vertices.push_back(0.0f);
                vertices.push_back(0.0f);
            }

            if (uv){
                glm::vec2 uvs = m_Mesh.m_VertexUV[i];
                vertices.push_back(uvs[0]);
                vertices.push_back(uvs[1]);
            }
            else
            {
                vertices.push_back(0.0f);
                vertices.push_back(0.0f);
            }

            if (color){
                glm::vec4 col = m_Mesh.m_VertexColor[i];
                vertices.push_back(col[0]);
                vertices.push_back(col[1]);
                vertices.push_back(col[2]);
                vertices.push_back(col[3]);
            }
            else
            {
                vertices.push_back(1.0f);
                vertices.push_back(1.0f);
                vertices.push_back(1.0f);
                vertices.push_back(1.0f);
            }            
        }

        m_VB->Bind();
        m_VB->WriteData(0, numberOfVertex * OpenglToolKit::Mesh::m_MaxSizeOfVertex, vertices.data()); // write vertices in VertexBuffer
        
        unsigned int * indices = m_Mesh.m_Triangles.data();

        m_IndexBuffer->Bind();
        m_IndexBuffer->WriteData(0, m_Mesh.m_Triangles.size(), indices); // write indices in IndexBuffer
    }

    void Test2_MeshTransform::OnRender()
    {
        easyGL::Renderer::Clear();

        m_Shader->Bind();
        easyGL::Renderer::Draw(*m_VAO, *m_IndexBuffer, *m_Shader);
    }

    void Test2_MeshTransform::OnImGuiRender()
    {
        ImGui::DragFloat3("Translation", m_Trans, 0.1f);
        ImGui::DragFloat3("Rotation", m_Rot, 0.1f);
        ImGui::DragFloat3("Scale", m_Scale, 0.1f);
    }
}