#pragma once

#include <GL/glew.h> // needs to be included first
#include <GLFW/glfw3.h>

#include<glm/glm.hpp>

namespace OpenglToolKit
{
    class WorldManager
    {
        private:
            static WorldManager* m_Instance;

            WorldManager()
                :m_ViewMatrix(1.0f), m_ProjectionMatrix(1.0f) { }
            ~WorldManager(){
                if (m_Instance){
                    delete m_Instance;
                }
            }
            
        public:
            static WorldManager* Instance()
            {
                if (!m_Instance){
                    m_Instance = new WorldManager();
                }
                return m_Instance;
            }

            GLFWwindow * m_Window;
            glm::mat4 m_ViewMatrix;
            glm::mat4 m_ProjectionMatrix;

            bool Init(int width, int height);
            int CheckCloseFlag();
            void InitFrame();
            void EndFrame();
            void Terminate();

            void GetWindowSize(int* width, int* height);
    };
    
} // namespace OpenglToolKit
