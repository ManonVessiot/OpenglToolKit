################################################################################
#                                   MAKEFILE                                   #
################################################################################

INC = -I /usr/include/

TESTS = Test.o TestTemplate.o Test1_Mesh.o

all: $(TESTS)

Test1_Mesh.o: Test1_Mesh.cpp Test1_Mesh.h Test.h
	$(CXX) -c Test1_Mesh.cpp $(INC)

TestTemplate.o: TestTemplate.cpp TestTemplate.h Test.h
	$(CXX) -c TestTemplate.cpp $(INC)

Test.o: Test.cpp Test.h
	$(CXX) -c Test.cpp $(INC)

clean :
	rm -f *.o