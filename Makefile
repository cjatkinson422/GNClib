INC = -g -std=c++17


default: executable

UnitTest.o: unit_tests/* *.hh
	g++ -c $(INC) unit_tests/quaternion_utest.cc
	g++ -c $(INC) unit_tests/UnitTest.cc


linalg.o: linalg.cc *.hh
	g++ -c $(INC) linalg.cc
vec3f.o: vec3f.cc *.hh
	g++ -c $(INC) vec3f.cc
vec3.o: vec3.cc *.hh
	g++ -c $(INC) vec3.cc
dynamics.o: dynamics.cc *.hh
	g++ -c $(INC) dynamics.cc
quaternion.o: quaternion.cc *.hh
	g++ -c $(INC) quaternion.cc

executable: linalg.o vec3f.o UnitTest.o dynamics.o quaternion.o vec3.o
	g++ $(INC) -o UnitTest linalg.o vec3f.o UnitTest.o dynamics.o quaternion.o vec3.o quaternion_utest.o
	ar rvs liblinalg.a linalg.o vec3f.o dynamics.o quaternion.o vec3.o
	./UnitTest

clean: 
	rm UnitTest || true
	rm *.o || true