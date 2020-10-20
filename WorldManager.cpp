#include "WorldManager.h"

#include "../easyGL/Renderer.h"

#include <glm/gtx/matrix_decompose.hpp>

namespace OpenglToolKit
{
    WorldManager* WorldManager::m_Instance = nullptr;

    bool WorldManager::Init(int width, int height){
        // Initialize the library
        if (!glfwInit()){
            return false;
        }

        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

        // Create a windowed mode window and its OpenGL context
        m_Window = glfwCreateWindow(width, height, "OpenglToolKit", NULL, NULL);
        if (!m_Window){
            glfwTerminate();
            return false;
        }

        // Make the window's context current
        glfwMakeContextCurrent(m_Window);

        glfwSwapInterval(3);

        // Init glew after making context current 
        if (glewInit() != GLEW_OK){
            std::cout << "Error!" << std::endl;
        }
        std::cout << glGetString(GL_VERSION) << std::endl;

        return true;
    }

    int WorldManager::CheckCloseFlag() const{
        return glfwWindowShouldClose(m_Window);
    }

    void WorldManager::InitFrame() const{
        easyGL::Renderer::Clear();
    }

    void WorldManager::EndFrame() const{
        // Swap front and back buffers
        glfwSwapBuffers(m_Window);

        // Poll for and process events
        glfwPollEvents();
    }

    void WorldManager::Terminate() const{
        glfwTerminate();
    }

    
    void WorldManager::GetWindowSize(int* width, int* height) const{
        glfwGetWindowSize(m_Window, width, height);
    }

    void WorldManager::GetCameraTransform(glm::vec3 &position, glm::quat &rotation) const{
        glm::mat4 viewInverse = glm::inverse(m_ViewMatrix);

        glm::vec3 scale;
        glm::vec3 skew;
        glm::vec4 perspective;
        glm::decompose(viewInverse, scale, rotation, position, skew, perspective);       
    }
} // namespace OpenglToolKit