INC = -g -std=c++17


default: executable

UnitTest.o: UnitTest.cc *.hh
	g++ -c $(INC) UnitTest.cc
linalg.o: linalg.cc *.hh
	g++ -c $(INC) linalg.cc

executable: linalg.o UnitTest.o
	g++ $(INC) -o UnitTest linalg.o UnitTest.o
	ar rvs liblinalg.a linalg.o
	./UnitTest

clean: 
	rm UnitTest
	rm *.o 