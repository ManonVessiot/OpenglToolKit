#include "Test4_BatchManager.h"

#include "../easyGL/Renderer.h"

#include "../vendor/imgui/imgui.h"

#include "../OpenglToolKit/GameObjectManager.h"
#include "../OpenglToolKit/BatchManager.h"
#include "../OpenglToolKit/MaterialManager.h"
#include "../OpenglToolKit/WorldManager.h"

#include "../easyGL/TextureManager.h"


namespace tests {
    Test4_BatchManager::Test4_BatchManager()
        :m_active1(true),
         m_Trans1{   0.5f,  0.0f,  0.0f},
         m_Rot1{     0.0f,  0.0f,  0.0f},
         m_Scale1{   0.3f,  0.3f,  0.3f},
         m_active2(true),
         m_Trans2{  -0.5f,  0.0f,  0.0f},
         m_Rot2{     0.0f,  0.0f,  0.0f},
         m_Scale2{   0.3f,  0.3f,  0.3f}
    {
        m_GameObject1.m_Mesh.Clear();
        m_GameObject1.m_Mesh.AddVertex(glm::vec3(-0.5f, -0.5f, 0.0f), glm::vec3(0.0f), glm::vec4(0.0f), glm::vec2(0.0f, 0.0f), glm::vec4(1.0f));
        m_GameObject1.m_Mesh.AddVertex(glm::vec3( 0.5f, -0.5f, 0.0f), glm::vec3(0.0f), glm::vec4(0.0f), glm::vec2(1.0f, 0.0f), glm::vec4(1.0f));
        m_GameObject1.m_Mesh.AddVertex(glm::vec3( 0.5f,  0.5f, 0.0f), glm::vec3(0.0f), glm::vec4(0.0f), glm::vec2(1.0f, 1.0f), glm::vec4(1.0f));
        m_GameObject1.m_Mesh.AddVertex(glm::vec3(-0.5f,  0.5f, 0.0f), glm::vec3(0.0f), glm::vec4(0.0f), glm::vec2(0.0f, 1.0f), glm::vec4(1.0f));

        m_GameObject1.m_Mesh.AddTriangle(0, 1, 2);
        m_GameObject1.m_Mesh.AddTriangle(2, 3, 0);

        m_GameObject1.m_Material = OpenglToolKit::MaterialManager::Instance()->CreateMaterial("shaders/ShaderBase.shader");
        m_GameObject1.m_Material->SetMainColor(1.0f, 0.0f, 0.0f, 1.0f);        
        m_GameObject1.m_Material->SetMainTexture(easyGL::TextureManager::Instance()->CreateTexture("textures/white.png"));


        m_GameObject2.m_Mesh.Clear();
        m_GameObject2.m_Mesh.AddVertex(glm::vec3(-0.5f, -0.5f, 0.0f), glm::vec3(0.0f), glm::vec4(0.0f), glm::vec2(0.0f, 0.0f), glm::vec4(1.0f));
        m_GameObject2.m_Mesh.AddVertex(glm::vec3( 0.5f, -0.5f, 0.0f), glm::vec3(0.0f), glm::vec4(0.0f), glm::vec2(1.0f, 0.0f), glm::vec4(1.0f));
        m_GameObject2.m_Mesh.AddVertex(glm::vec3( 0.5f,  0.5f, 0.0f), glm::vec3(0.0f), glm::vec4(0.0f), glm::vec2(1.0f, 1.0f), glm::vec4(1.0f));
        m_GameObject2.m_Mesh.AddVertex(glm::vec3(-0.5f,  0.5f, 0.0f), glm::vec3(0.0f), glm::vec4(0.0f), glm::vec2(0.0f, 1.0f), glm::vec4(1.0f));

        m_GameObject2.m_Mesh.AddTriangle(0, 1, 2);
        m_GameObject2.m_Mesh.AddTriangle(2, 3, 0);

        m_GameObject2.m_Material = OpenglToolKit::MaterialManager::Instance()->CreateMaterial("shaders/ShaderBase.shader");
        m_GameObject2.m_Material->SetMainColor(1.0f, 0.0f, 0.0f, 1.0f);        
        m_GameObject2.m_Material->SetMainTexture(easyGL::TextureManager::Instance()->CreateTexture("textures/white.png"));

        OpenglToolKit::BatchManager::Init(20, 2000, 1000);
    }

    Test4_BatchManager::~Test4_BatchManager()
    {
    }

    void Test4_BatchManager::OnUpdate(float deltaTime)
    {
        m_GameObject1.SetActive(m_active1);
        m_GameObject1.m_Transform.m_Position = glm::vec3(m_Trans1[0], m_Trans1[1], m_Trans1[2]);
        m_GameObject1.m_Transform.m_Rotation = glm::quat(glm::vec3(glm::radians(m_Rot1[0]), glm::radians(m_Rot1[1]), glm::radians(m_Rot1[2])));
        m_GameObject1.m_Transform.m_Scale = glm::vec3(m_Scale1[0], m_Scale1[1], m_Scale1[2]);

        m_GameObject2.SetActive(m_active2);
        m_GameObject2.m_Transform.m_Position = glm::vec3(m_Trans2[0], m_Trans2[1], m_Trans2[2]);
        m_GameObject2.m_Transform.m_Rotation = glm::quat(glm::vec3(glm::radians(m_Rot2[0]), glm::radians(m_Rot2[1]), glm::radians(m_Rot2[2])));
        m_GameObject2.m_Transform.m_Scale = glm::vec3(m_Scale2[0], m_Scale2[1], m_Scale2[2]);
    }

    void Test4_BatchManager::OnRender()
    {
        OpenglToolKit::GameObjectManager::Instance()->Render();
        OpenglToolKit::BatchManager::Instance()->EmptyAll();
    }

    void Test4_BatchManager::OnImGuiRender()
    {
        ImGui::DragFloat3("Translation 1", m_Trans1, 0.1f);
        ImGui::DragFloat3("Rotation 1", m_Rot1, 0.1f);
        ImGui::DragFloat3("Scale 1", m_Scale1, 0.1f);
        if (ImGui::Button("De/Active 1")){
            m_active1 = !m_active1;
        }
        
        ImGui::DragFloat3("Translation 2", m_Trans2, 0.1f);
        ImGui::DragFloat3("Rotation 2", m_Rot2, 0.1f);
        ImGui::DragFloat3("Scale 2", m_Scale2, 0.1f);
        if (ImGui::Button("De/Active 2")){
            m_active2 = !m_active2;
        }
    }
}