INC = -g -std=c++17

default: executable

UnitTest.o: UnitTest.cpp *.hpp
	g++ -c $(INC) UnitTest.cpp
linalg.o: linalg.cpp *.hpp
	g++ -c $(INC) linalg.cpp
orbits.o: orbits.cpp *.hpp
	g++ -c $(INC) orbits.cpp

executable: linalg.o orbits.o UnitTest.o
	g++ $(INC) -o UnitTest linalg.o orbits.o UnitTest.o
	./UnitTest

clean: 
	rm UnitTest
	rm *.o 
