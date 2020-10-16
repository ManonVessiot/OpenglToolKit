################################################################################
#                                   MAKEFILE                                   #
################################################################################

INC = -I /usr/include/

TESTS = Test.o Test1_GameObject.o Test2_Material.o Test3_Batching.o Test4_BatchManager.o

all: $(TESTS)

Test4_BatchManager.o: Test4_BatchManager.cpp Test4_BatchManager.h Test.h
	$(CXX) -c Test4_BatchManager.cpp $(INC)

Test3_Batching.o: Test3_Batching.cpp Test3_Batching.h Test.h
	$(CXX) -c Test3_Batching.cpp $(INC)

Test2_Material.o: Test2_Material.cpp Test2_Material.h Test.h
	$(CXX) -c Test2_Material.cpp $(INC)

Test1_GameObject.o: Test1_GameObject.cpp Test1_GameObject.h Test.h
	$(CXX) -c Test1_GameObject.cpp $(INC)

Test.o: Test.cpp Test.h
	$(CXX) -c Test.cpp $(INC)

clean :
	rm -f *.o