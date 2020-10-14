################################################################################
#                                   MAKEFILE                                   #
################################################################################

INC = -I /usr/include/

TESTS = Test.o TestTemplate.o

all: $(TESTS)

Test.o: Test.cpp Test.h
	$(CXX) -c Test.cpp $(INC)

TestTemplate.o: TestTemplate.cpp TestTemplate.h Test.h
	$(CXX) -c TestTemplate.cpp $(INC)

clean :
	rm -f *.o