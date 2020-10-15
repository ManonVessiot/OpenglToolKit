################################################################################
#                                   MAKEFILE                                   #
################################################################################

OPENGL_LIBS =  -lglfw -lGLEW -lGL

LIBS = $(OPENGL_LIBS)

INC = -I /usr/include/

VENDOR_O = ./easyGL/vendor/stb_image/stb_image.o ./vendor/imgui/imgui.o ./vendor/imgui/imgui_impl_glfw.o \
	./vendor/imgui/imgui_impl_opengl3.o ./vendor/imgui/imgui_widgets.o ./vendor/imgui/imgui_draw.o \
	./vendor/imgui/imgui_demo.o

TESTS = ./tests/Test.o ./tests/TestTemplate.o ./tests/Test1_Mesh.o ./tests/Test2_GameObject.o

EASY_GL = ./easyGL/Renderer.o ./easyGL/VertexBuffer.o ./easyGL/IndexBuffer.o ./easyGL/VertexArray.o \
	./easyGL/VertexBufferLayout.o ./easyGL/Shader.o ./easyGL/Texture.o

LOCAL = main.o WorldManager.o ImGuiManager.o Mesh.o Transform.o GameObject.o

all: $(LOCAL)

GameObject.o: GameObject.cpp GameObject.h
	$(CXX) -c GameObject.cpp $(INC)

Transform.o: Transform.cpp Transform.h
	$(CXX) -c Transform.cpp $(INC)

Mesh.o: Mesh.cpp Mesh.h
	$(CXX) -c Mesh.cpp $(INC)

ImGuiManager.o: ImGuiManager.cpp ImGuiManager.h
	$(CXX) -c ImGuiManager.cpp $(INC)

WorldManager.o: WorldManager.cpp WorldManager.h
	$(CXX) -c WorldManager.cpp $(INC)

main.o: main.cpp WorldManager.h ImGuiManager.h Mesh.h Transform.h GameObject.h
	$(CXX) -c main.cpp $(INC)

exc: $(LOCAL) $(EASY_GL) $(TESTS) $(VENDOR_O)
	$(CXX) -o exc $(LOCAL) $(EASY_GL) $(TESTS) $(VENDOR_O) $(LIBS)

clean :
	rm -f *.o exc imgui.ini