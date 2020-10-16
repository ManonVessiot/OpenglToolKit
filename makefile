################################################################################
#                                   MAKEFILE                                   #
################################################################################

OPENGL_LIBS =  -lglfw -lGLEW -lGL

LIBS = $(OPENGL_LIBS)

INC = -I /usr/include/

VENDOR_O = ./easyGL/vendor/stb_image/stb_image.o ./vendor/imgui/imgui.o ./vendor/imgui/imgui_impl_glfw.o \
	./vendor/imgui/imgui_impl_opengl3.o ./vendor/imgui/imgui_widgets.o ./vendor/imgui/imgui_draw.o \
	./vendor/imgui/imgui_demo.o

TESTS = ./tests/Test.o ./tests/Test1_GameObject.o ./tests/Test2_Material.o ./tests/Test3_Batching.o ./tests/Test4_BatchManager.o

EASY_GL = ./easyGL/Renderer.o ./easyGL/VertexBuffer.o ./easyGL/IndexBuffer.o ./easyGL/VertexArray.o \
	./easyGL/VertexBufferLayout.o ./easyGL/Shader.o ./easyGL/Texture.o

LOCAL = main.o WorldManager.o ImGuiManager.o Mesh.o Transform.o GameObject.o Material.o MaterialManager.o TextureManager.o \
	ShaderManager.o Batch.o BatchManager.o

all: $(LOCAL)

BatchManager.o: BatchManager.cpp BatchManager.h
	$(CXX) -c BatchManager.cpp $(INC)

Batch.o: Batch.cpp Batch.h
	$(CXX) -c Batch.cpp $(INC)

ShaderManager.o: ShaderManager.cpp ShaderManager.h
	$(CXX) -c ShaderManager.cpp $(INC)

TextureManager.o: TextureManager.cpp TextureManager.h
	$(CXX) -c TextureManager.cpp $(INC)

MaterialManager.o: MaterialManager.cpp MaterialManager.h
	$(CXX) -c MaterialManager.cpp $(INC)

Material.o: Material.cpp Material.h
	$(CXX) -c Material.cpp $(INC)

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