INC = -g -std=c++17


default: executable

UnitTest.o: unit_tests/* *.hh
	g++ -c $(INC) unit_tests/quaternion_utest.cc
	g++ -c $(INC) unit_tests/UnitTest.cc


linalg.o: linalg.cc *.hh
	g++ -c $(INC) linalg.cc
dynamics.o: dynamics.cc *.hh
	g++ -c $(INC) dynamics.cc
quaternion.o: quaternion.cc *.hh
	g++ -c $(INC) quaternion.cc

executable: linalg.o UnitTest.o dynamics.o quaternion.o
	g++ $(INC) -o UnitTest linalg.o UnitTest.o dynamics.o quaternion.o quaternion_utest.o
	ar rvs liblinalg.a linalg.o dynamics.o quaternion.o
	./UnitTest

clean: 
	rm UnitTest || true
	rm *.o || true