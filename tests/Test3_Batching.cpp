#include "Test3_Batching.h"

#include "../easyGL/Renderer.h"

#include "../vendor/imgui/imgui.h"


namespace tests {
    Test3_Batching::Test3_Batching()
        :m_Trans1{   0.5f,  0.0f,  0.0f},
         m_Rot1{     0.0f,  0.0f,  0.0f},
         m_Scale1{   0.3f,  0.3f,  0.3f},
         m_Trans2{  -0.5f,  0.0f,  0.0f},
         m_Rot2{     0.0f,  0.0f,  0.0f},
         m_Scale2{   0.3f,  0.3f,  0.3f}
    {
        m_GameObject.m_Mesh.Clear();
        m_GameObject.m_Mesh.AddVertex(glm::vec3(-0.5f, -0.5f, 0.0f), glm::vec3(0.0f), glm::vec4(0.0f), glm::vec2(0.0f, 0.0f), glm::vec4(1.0f));
        m_GameObject.m_Mesh.AddVertex(glm::vec3( 0.5f, -0.5f, 0.0f), glm::vec3(0.0f), glm::vec4(0.0f), glm::vec2(1.0f, 0.0f), glm::vec4(1.0f));
        m_GameObject.m_Mesh.AddVertex(glm::vec3( 0.5f,  0.5f, 0.0f), glm::vec3(0.0f), glm::vec4(0.0f), glm::vec2(1.0f, 1.0f), glm::vec4(1.0f));
        m_GameObject.m_Mesh.AddVertex(glm::vec3(-0.5f,  0.5f, 0.0f), glm::vec3(0.0f), glm::vec4(0.0f), glm::vec2(0.0f, 1.0f), glm::vec4(1.0f));

        m_GameObject.m_Mesh.AddTriangle(0, 1, 2);
        m_GameObject.m_Mesh.AddTriangle(2, 3, 0);


        m_Batch = std::make_unique<OpenglToolKit::Batch>(300, 300);
    }

    Test3_Batching::~Test3_Batching()
    {
    }

    void Test3_Batching::OnUpdate(float deltaTime)
    {
        unsigned int numberOfVertex = m_GameObject.m_Mesh.m_Vertices.size();

        {
            m_GameObject.m_Transform.m_Position = glm::vec3(m_Trans1[0], m_Trans1[1], m_Trans1[2]);
            m_GameObject.m_Transform.m_Rotation = glm::quat(glm::vec3(glm::radians(m_Rot1[0]), glm::radians(m_Rot1[1]), glm::radians(m_Rot1[2])));
            m_GameObject.m_Transform.m_Scale = glm::vec3(m_Scale1[0], m_Scale1[1], m_Scale1[2]);
            glm::mat4 transformMatrix = m_GameObject.m_Transform.GetTransformMatrix();


            std::vector<OpenglToolKit::VertexData> vertices;
            for (int i = 0; i < numberOfVertex; i++){
                vertices.push_back(m_GameObject.m_Mesh.m_Vertices[i]);
                vertices[i].Position = transformMatrix * glm::vec4(vertices[i].Position, 1.0f);       
            }
            std::vector<unsigned int> triangles = m_GameObject.m_Mesh.m_Triangles;

            m_Batch->AddData(vertices, triangles);
        }
        {
            m_GameObject.m_Transform.m_Position = glm::vec3(m_Trans2[0], m_Trans2[1], m_Trans2[2]);
            m_GameObject.m_Transform.m_Rotation = glm::quat(glm::vec3(glm::radians(m_Rot2[0]), glm::radians(m_Rot2[1]), glm::radians(m_Rot2[2])));
            m_GameObject.m_Transform.m_Scale = glm::vec3(m_Scale2[0], m_Scale2[1], m_Scale2[2]);
            glm::mat4 transformMatrix = m_GameObject.m_Transform.GetTransformMatrix();


            std::vector<OpenglToolKit::VertexData> vertices;
            for (int i = 0; i < numberOfVertex; i++){
                vertices.push_back(m_GameObject.m_Mesh.m_Vertices[i]);
                vertices[i].Position = transformMatrix * glm::vec4(vertices[i].Position, 1.0f);       
            }
            std::vector<unsigned int> triangles = m_GameObject.m_Mesh.m_Triangles;

            m_Batch->AddData(vertices, triangles);
        }
    }

    void Test3_Batching::OnRender()
    {
        m_Batch->Render();
        m_Batch = std::make_unique<OpenglToolKit::Batch>(300, 300);
    }

    void Test3_Batching::OnImGuiRender()
    {
        ImGui::DragFloat3("Translation 1", m_Trans1, 0.1f);
        ImGui::DragFloat3("Rotation 1", m_Rot1, 0.1f);
        ImGui::DragFloat3("Scale 1", m_Scale1, 0.1f);
        
        ImGui::DragFloat3("Translation 2", m_Trans2, 0.1f);
        ImGui::DragFloat3("Rotation 2", m_Rot2, 0.1f);
        ImGui::DragFloat3("Scale 2", m_Scale2, 0.1f);
    }
}