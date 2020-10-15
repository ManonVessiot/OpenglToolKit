################################################################################
#                                   MAKEFILE                                   #
################################################################################

INC = -I /usr/include/

TESTS = Test.o Test1_Mesh.o Test2_GameObject.o

all: $(TESTS)

Test2_GameObject.o: Test2_GameObject.cpp Test2_GameObject.h Test.h
	$(CXX) -c Test2_GameObject.cpp $(INC)

Test1_Mesh.o: Test1_Mesh.cpp Test1_Mesh.h Test.h
	$(CXX) -c Test1_Mesh.cpp $(INC)

Test.o: Test.cpp Test.h
	$(CXX) -c Test.cpp $(INC)

clean :
	rm -f *.o