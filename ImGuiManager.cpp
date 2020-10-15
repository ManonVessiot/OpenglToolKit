#include "ImGuiManager.h"

#include "vendor/imgui/imgui.h"
#include "vendor/imgui/imgui_impl_glfw.h"
#include "vendor/imgui/imgui_impl_opengl3.h"

#include "WorldManager.h"

#include <string>

namespace OpenglToolKit
{
    ImGuiManager* ImGuiManager::m_Instance = nullptr;

    void ImGuiManager::Init_imgui(){
        ImGui::CreateContext();
        ImGui::StyleColorsDark();
        ImGui_ImplGlfw_InitForOpenGL(WorldManager::Instance()->m_Window, true);
        ImGui_ImplOpenGL3_Init("#version 130");
    }

    void ImGuiManager::InitFrame_imgui(){        
        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();
    }

    void ImGuiManager::Render_imgui(){
        ImGui::Render();
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
    }

    void ImGuiManager::Destroy_imgui(){
        ImGui_ImplOpenGL3_Shutdown();
        ImGui_ImplGlfw_Shutdown();
        // ImGui::DestroyContext(); // create a file
    }

    bool ImGuiManager::StartWindow(const char* windowsName){
        return ImGui::Begin(windowsName);
    }
    void ImGuiManager::EndWindow(){
        ImGui::End();
    }
    bool ImGuiManager::CreateButton(const char* buttonName){
        return ImGui::Button(buttonName);
    }
    
} // namespace OpenglToolKit