INC = -g -std=c++17


default: executable

UnitTest.o: UnitTest.cpp *.hpp
	g++ -c $(INC) UnitTest.cpp
linalg.o: linalg.cpp *.hpp
	g++ -c $(INC) linalg.cpp

executable: linalg.o UnitTest.o
	g++ $(INC) -o UnitTest linalg.o UnitTest.o
	ar rvs liblinalg.a linalg.o
	./UnitTest

clean: 
	rm UnitTest
	rm *.o 