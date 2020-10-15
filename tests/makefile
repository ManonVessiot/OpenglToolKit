################################################################################
#                                   MAKEFILE                                   #
################################################################################

INC = -I /usr/include/

TESTS = Test.o Test1_Mesh.o Test2_MeshTransform.o

all: $(TESTS)

Test2_MeshTransform.o: Test2_MeshTransform.cpp Test2_MeshTransform.h Test.h
	$(CXX) -c Test2_MeshTransform.cpp $(INC)

Test1_Mesh.o: Test1_Mesh.cpp Test1_Mesh.h Test.h
	$(CXX) -c Test1_Mesh.cpp $(INC)

Test.o: Test.cpp Test.h
	$(CXX) -c Test.cpp $(INC)

clean :
	rm -f *.o