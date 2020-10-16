################################################################################
#                                   MAKEFILE                                   #
################################################################################

INC = -I /usr/include/

TESTS = Test.o Test2_GameObject.o Test3_Batching.o

all: $(TESTS)

Test3_Batching.o: Test3_Batching.cpp Test3_Batching.h Test.h
	$(CXX) -c Test3_Batching.cpp $(INC)

Test2_GameObject.o: Test2_GameObject.cpp Test2_GameObject.h Test.h
	$(CXX) -c Test2_GameObject.cpp $(INC)

Test.o: Test.cpp Test.h
	$(CXX) -c Test.cpp $(INC)

clean :
	rm -f *.o