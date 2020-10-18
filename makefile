################################################################################
#                                   MAKEFILE                                   #
################################################################################

INC = -I /usr/include/

OPENGL_TOOLKIT = WorldManager.o Mesh.o Transform.o GameObject.o GameObjectManager.o Material.o MaterialManager.o \
	Batch.o BatchManager.o MeshBuilder.o

all: $(OPENGL_TOOLKIT)

MeshBuilder.o: MeshBuilder.cpp MeshBuilder.h
	$(CXX) -c MeshBuilder.cpp $(INC)

BatchManager.o: BatchManager.cpp BatchManager.h
	$(CXX) -c BatchManager.cpp $(INC)

Batch.o: Batch.cpp Batch.h
	$(CXX) -c Batch.cpp $(INC)

MaterialManager.o: MaterialManager.cpp MaterialManager.h
	$(CXX) -c MaterialManager.cpp $(INC)

Material.o: Material.cpp Material.h
	$(CXX) -c Material.cpp $(INC)

GameObjectManager.o: GameObjectManager.cpp GameObjectManager.h
	$(CXX) -c GameObjectManager.cpp $(INC)

GameObject.o: GameObject.cpp GameObject.h
	$(CXX) -c GameObject.cpp $(INC)

Transform.o: Transform.cpp Transform.h
	$(CXX) -c Transform.cpp $(INC)

Mesh.o: Mesh.cpp Mesh.h
	$(CXX) -c Mesh.cpp $(INC)

WorldManager.o: WorldManager.cpp WorldManager.h
	$(CXX) -c WorldManager.cpp $(INC)

clean :
	rm -f *.o