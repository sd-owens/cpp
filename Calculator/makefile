#/************************************************************************
#** Program name: Matrix Determinant Caculator Makefile
#** Author: Steven Owens
#** Date: 9/29/2019
#** Description:  Program to calculate the determinant of a matrix of size
#** 2x2 or 3x3. Provides functionality for user to choose size of matrix
#** and input integer data with error handling to prevent input of invalid
#** data and safeguard againgst erroneous results.
#************************************************************************/

# makefile syntax adapted from example provided TA Harlan James <waldroha@oregonstat.edu> 
# with snippet VOPT for valgrind directly incorporated.

CXX = g++ 
CXXVER = -std=c++11
CXXFLAGS = -Wall -g

VOPT = --tool=memcheck --leak-check=full --show-leak-kinds=all --track-origins=yes

OBJECTS = main.o determinant.o readMatrix.o

main: main.o determinant.o readMatrix.o
	$(CXX) $(CXXFLAGS) $(CXXVER) -o main $(OBJECTS)

main.o: main.cpp determinant.hpp readMatrix.hpp
	$(CXX) $(CXXFLAGS) $(CXXVER) -c main.cpp

determinant.o: determinant.hpp

readMatrix.o: readMatrix.hpp

clean:
	-rm main $(OBJECTS)

debug: main
	@valgrind $(VOPT) ./main