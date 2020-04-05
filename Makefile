INC = -g -std=c++17


default: executable

UnitTest.o: UnitTest.cc *.hh
	g++ -c $(INC) UnitTest.cc
linalg.o: linalg.cc *.hh
	g++ -c $(INC) linalg.cc
dynamics.o: dynamics.cc *.hh
	g++ -c $(INC) dynamics.cc
quaternion.o: quaternion.cc *.hh
	g++ -c $(INC) quaternion.cc

executable: linalg.o UnitTest.o dynamics.o quaternion.o
	g++ $(INC) -o UnitTest linalg.o UnitTest.o dynamics.o quaternion.o
	ar rvs liblinalg.a linalg.o dynamics.o quaternion.o
	./UnitTest

clean: 
	rm UnitTest
	rm *.o 