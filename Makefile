INC = -g -std=c++17

default: executable

UnitTest.o: UnitTest.cpp *.hpp
	g++ -c $(INC) UnitTest.cpp
linalg.o: linalg.cpp *.hpp
	g++ -c $(INC) linalg.cpp
astrodynamics.o: astrodynamics.cpp *.hpp
	g++ -c $(INC) astrodynamics.cpp

lib: linalg.o astrodynamics.o
	ar rvs libGNClib.a linalg.o astrodynamics.o
executable: linalg.o astrodynamics.o UnitTest.o
	g++ $(INC) -o UnitTest linalg.o astrodynamics.o UnitTest.o
	./UnitTest

clean: 
	rm UnitTest
	rm *.o 
	rm *.a
