################################################################################
#                                   MAKEFILE                                   #
################################################################################

OPENGL_LIBS =  -lglfw -lGLEW -lGL

LIBS = $(OPENGL_LIBS)

INC = -I /usr/include/

VENDOR_O = ./easyGL/vendor/stb_image/stb_image.o ./vendor/imgui/imgui.o ./vendor/imgui/imgui_impl_glfw.o \
	./vendor/imgui/imgui_impl_opengl3.o ./vendor/imgui/imgui_widgets.o ./vendor/imgui/imgui_draw.o \
	./vendor/imgui/imgui_demo.o

TESTS = ./tests/Test.o ./tests/Test1_GameObject.o ./tests/Test2_Material.o ./tests/Test3_ZBuffer.o \
	./tests/Test4_BatchManager.o ./tests/Test5_MeshBuilder.o

EASY_GL = ./easyGL/Renderer.o ./easyGL/VertexBuffer.o ./easyGL/IndexBuffer.o ./easyGL/VertexArray.o \
	./easyGL/VertexBufferLayout.o ./easyGL/Shader.o ./easyGL/Texture.o ./easyGL/TextureManager.o ./easyGL/ShaderManager.o

OPENGL_TOOLKIT = ./OpenglToolKit/WorldManager.o ./OpenglToolKit/ImGuiManager.o ./OpenglToolKit/Mesh.o ./OpenglToolKit/Transform.o \
	./OpenglToolKit/GameObject.o ./OpenglToolKit/GameObjectManager.o ./OpenglToolKit/Material.o ./OpenglToolKit/MaterialManager.o \
	./OpenglToolKit/Batch.o ./OpenglToolKit/BatchManager.o ./OpenglToolKit/MeshBuilder.o

LOCAL = main.o 

all: exc

main.o: main.cpp
	$(CXX) -c main.cpp $(INC)

exc: $(LOCAL) $(OPENGL_TOOLKIT) $(EASY_GL) $(TESTS) $(VENDOR_O)
	$(CXX) -o exc $(LOCAL) $(OPENGL_TOOLKIT) $(EASY_GL) $(TESTS) $(VENDOR_O) $(LIBS)

clean :
	rm -f *.o exc imgui.ini