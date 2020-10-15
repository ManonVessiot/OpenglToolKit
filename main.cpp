#include "WorldManager.h"
#include "ImGuiManager.h"

#include "tests/Test.h"
#include "tests/TestTemplate.h"
#include "tests/Test1_Mesh.h"

int main(int argc, char const *argv[])
{
    OpenglToolKit::WorldManager* worldManager = OpenglToolKit::WorldManager::Instance();
    OpenglToolKit::ImGuiManager* imGuiManager = OpenglToolKit::ImGuiManager::Instance();

    int height = 620;
    int width = 620;
    if (!worldManager->Init(width, height)){
        return -1;
    }
    imGuiManager->Init_imgui();
    {
        tests::Test* currentTest = nullptr;
        tests::TestMenu* testMenu = new tests::TestMenu(currentTest);
        currentTest = testMenu;

        testMenu->RegisterTest<tests::TestTemplate>("TestTemplate");
        testMenu->RegisterTest<tests::Test1_Mesh>("Test1_Mesh");

        // Loop until the user closes the window
        while (!worldManager->CheckCloseFlag())
        {
            worldManager->InitFrame();
            imGuiManager->InitFrame_imgui();

            if (currentTest)
            {
                currentTest->OnUpdate(0.0f);
                currentTest->OnRender();
                imGuiManager->StartWindow("Test");
                if (currentTest != testMenu && imGuiManager->CreateButton("<-"))
                {
                    delete currentTest;
                    currentTest = testMenu;
                }
                currentTest->OnImGuiRender();
                imGuiManager->EndWindow();
            }

            imGuiManager->Render_imgui();

            worldManager->EndFrame();
        }
        delete currentTest;
        if (currentTest != testMenu){
            delete testMenu;
        }
    }
    imGuiManager->Destroy_imgui();
    worldManager->Terminate();
    return 0;
}