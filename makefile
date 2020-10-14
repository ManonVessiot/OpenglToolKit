################################################################################
#                                   MAKEFILE                                   #
################################################################################

OPENGL_LIBS =  -lglfw -lGLEW -lGL

LIBS = $(OPENGL_LIBS)

INC = -I /usr/include/

VENDOR_O = ./easyGL/vendor/stb_image/stb_image.o ./vendor/imgui/imgui.o ./vendor/imgui/imgui_impl_glfw.o \
	./vendor/imgui/imgui_impl_opengl3.o ./vendor/imgui/imgui_widgets.o ./vendor/imgui/imgui_draw.o \
	./vendor/imgui/imgui_demo.o

TESTS = ./tests/Test.o ./tests/TestTemplate.o

EASY_GL = ./easyGL/Renderer.o ./easyGL/VertexBuffer.o ./easyGL/IndexBuffer.o ./easyGL/VertexArray.o \
	./easyGL/VertexBufferLayout.o ./easyGL/Shader.o ./easyGL/Texture.o

LOCAL = main.o

all: $(LOCAL)

main.o: main.cpp
	$(CXX) -c main.cpp $(INC)

exc: $(LOCAL)
	$(CXX) -o exc $(LOCAL) $(EASY_GL) $(TESTS) $(VENDOR_O) $(LIBS)

clean :
	rm -f *.o exc