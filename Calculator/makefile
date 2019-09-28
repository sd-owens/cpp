CXX = g++ 
CXXVER = -std=c++11
CXXFLAGS = -Wall -g

# VOPT = --tool=memcheck --leak-check=full --show-leak-kinds=all --track-origins=yes

OBJECTS = main.o determinant.o readMatrix.o

main: main.o determinant.o readMatrix.o
	$(CXX) $(CXXFLAGS) $(CXXVER) -o main $(OBJECTS)

main.o: main.cpp determinant.hpp readMatrix.hpp
	$(CXX) $(CXXFLAGS) $(CXXVER) -c main.cpp

determinant.o: determinant.hpp
        $(CXX) $(CXXFLAGS) $(CXXVER) -c determinant.cpp

readMatrix.o: readMatrix.hpp
        $(CXX) $(CXXFLAGS) $(CXXVER) -c readMatrix.cpp
clean:
	-rm main $(OBJECTS)