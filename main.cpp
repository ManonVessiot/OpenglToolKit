
#include <GL/glew.h> // needs to be included first
#include <GLFW/glfw3.h>

#include <iostream>

#include "vendor/imgui/imgui.h"
#include "vendor/imgui/imgui_impl_glfw.h"
#include "vendor/imgui/imgui_impl_opengl3.h"

#include "easyGL/Renderer.h"

#include "tests/Test.h"
#include "tests/TestTemplate.h"

int main(int argc, char const *argv[])
{
    GLFWwindow * window;

    // Initialize the library
    if (!glfwInit()){
        return -1;
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    // Create a windowed mode window and its OpenGL context
    int height = 540;
    int width = 960;
    // glfwGetWindowSize(&width, &height);
    window = glfwCreateWindow(width, height, "OpenglToolKit", NULL, NULL);
    if (!window){
        glfwTerminate();
        return -1;
    }
    glfwGetWindowSize(window, &width, &height);

    // Make the window's context current
    glfwMakeContextCurrent(window);

    glfwSwapInterval(3);

    // Init glew after making context current 
    if (glewInit() != GLEW_OK){
        std::cout << "Error!" << std::endl;
    }
    std::cout << glGetString(GL_VERSION) << std::endl;
    {
        easyGL::Renderer::Blend();

        // ImGui : INIT
        ImGui::CreateContext();
        ImGui::StyleColorsDark();
        ImGui_ImplGlfw_InitForOpenGL(window, true);
        ImGui_ImplOpenGL3_Init("#version 130");

        tests::Test* currentTest = nullptr;
        tests::TestMenu* testMenu = new tests::TestMenu(currentTest);
        currentTest = testMenu;

        testMenu->RegisterTest<tests::TestTemplate>("TestTemplate");

        // Loop until the user closes the window
        while (!glfwWindowShouldClose(window))
        {
            easyGL::Renderer::Clear();

            // ImGui : INIT NEW FRAME
            ImGui_ImplOpenGL3_NewFrame();
            ImGui_ImplGlfw_NewFrame();
            ImGui::NewFrame();
            if (currentTest)
            {
                currentTest->OnUpdate(0.0f);
                currentTest->OnRender();
                ImGui::Begin("Test");
                if (currentTest != testMenu && ImGui::Button("<-"))
                {
                    delete currentTest;
                    currentTest = testMenu;
                }
                currentTest->OnImGuiRender();
                ImGui::End();
            }

            // ImGui : RENDER
            ImGui::Render();
            ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

            // Swap front and back buffers
            glfwSwapBuffers(window);

            // Poll for and process events
            glfwPollEvents();
        }
        delete currentTest;
        if (currentTest != testMenu){
            delete testMenu;
        }
    }
    // ImGui : DESTROY
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    // ImGui::DestroyContext(); // create a file

    glfwTerminate();
    return 0;
}