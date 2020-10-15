#pragma once

namespace OpenglToolKit
{
    class ImGuiManager
    {
    private:
        static ImGuiManager* m_Instance;

        ImGuiManager(){ }
        ~ImGuiManager(){
            if (m_Instance){
                delete m_Instance;
            }
        }
        
    public:
        static ImGuiManager* Instance()
        {
            if (!m_Instance){
                m_Instance = new ImGuiManager();
            }
            return m_Instance;
        }

        void Init_imgui();
        void InitFrame_imgui();
        void Render_imgui();
        void Destroy_imgui();

        bool StartWindow(const char* windowsName);
        void EndWindow();
        bool CreateButton(const char* buttonName);
    };
    
} // namespace OpenglToolKit
