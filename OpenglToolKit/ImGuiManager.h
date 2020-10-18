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

            void Init_imgui() const;
            void InitFrame_imgui() const;
            void Render_imgui() const;
            void Destroy_imgui() const;

            bool StartWindow(const char* windowsName) const;
            void EndWindow() const;
            bool CreateButton(const char* buttonName) const;
    };
    
} // namespace OpenglToolKit
