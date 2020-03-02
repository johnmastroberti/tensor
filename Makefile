CXX=g++
CXXFLAGS=-Wall -Wextra -Wpedantic -Weffc++ -std=c++17
LD=g++
test: test.cpp tensor.hpp
	$(CXX) $(CXXFLAGS) test.cpp -o test
