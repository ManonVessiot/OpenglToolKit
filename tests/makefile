################################################################################
#                                   MAKEFILE                                   #
################################################################################

INC = -I /usr/include/

TESTS = Test.o Test1_GameObject.o Test2_Material.o Test3_BatchManager.o

all: $(TESTS)

Test3_BatchManager.o: Test3_BatchManager.cpp Test3_BatchManager.h Test.h
	$(CXX) -c Test3_BatchManager.cpp $(INC)

Test2_Material.o: Test2_Material.cpp Test2_Material.h Test.h
	$(CXX) -c Test2_Material.cpp $(INC)

Test1_GameObject.o: Test1_GameObject.cpp Test1_GameObject.h Test.h
	$(CXX) -c Test1_GameObject.cpp $(INC)

Test.o: Test.cpp Test.h
	$(CXX) -c Test.cpp $(INC)

clean :
	rm -f *.o