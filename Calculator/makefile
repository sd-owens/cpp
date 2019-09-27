CXX = g++ 

CXXFLAGS = -Wall -g

OBJECTS = main.o determinant.o readMatrix.o

main: main.o determinant.o readMatrix.o
	$(CXX) $(CXXFLAGS) -o main $(OBJECTS)

main.o: main.cpp determinant.hpp readMatrix.hpp
	$(CXX) $(CXXFLAGS) -c main.cpp

determinant.o: determinant.hpp

readMatrix.o: readMatrix.hpp

clean:
	-rm main $(OBJECTS)