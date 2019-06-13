INC = -g -std=c++17


default: executable

UnitTest.o: UnitTest.cpp *.hpp
	g++ -c $(INC) UnitTest.cpp
linalg.o: linalg.cpp *.hpp
	g++ -c $(INC) linalg.cpp
rotations.o: rotations.cpp *.hpp
	g++ -c $(INC) rotations.cpp

executable: linalg.o rotations.o UnitTest.o
	g++ $(INC) -o UnitTest linalg.o rotations.o UnitTest.o

clean: rm *.o 