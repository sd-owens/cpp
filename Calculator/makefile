#/************************************************************************
#** Program name: Matrix Determinant Caculator
#** Author: Steven Owens
#** Date: 9/29/2019
#** Description:  Program to calculate the determinant of a matrix of size
#** 2x2 or 3x3. Provides functionality for user to choose size of matrix
#** and input integer data with error handling to prevent input of invalid
#** data and safeguard againgst erroneous results.  This program should be
#** compiled with the command "make" from the command line which produces
#** an executable named "mcalc". Run with the command ./mcalc
#************************************************************************/

# makefile syntax adapted from example provided TA Harlan James <waldroha@oregonstat.edu> 
# with snippet VOPT for valgrind directly incorporated.

CXX = g++
CXXVER = -std=c++11
CXXFLAGS = -Wall -g

VOPT = --tool=memcheck --leak-check=full --show-leak-kinds=all --track-origins=yes

OBJECTS = main.o determinant.o readMatrix.o

mcalc: main.o determinant.o readMatrix.o
	$(CXX) $(CXXVER) $(CXXFLAGS) -o mcalc $(OBJECTS)

main.o: main.cpp determinant.hpp readMatrix.hpp
	$(CXX) $(CXXVER) $(CXXFLAGS) -c main.cpp

determinant.o: determinant.hpp
	$(CXX) $(CXXVER) $(CXXFLAGS) -c determinant.cpp

readMatrix.o: readMatrix.hpp
	$(CXX) $(CXXVER) $(CXXFLAGS) -c readMatrix.cpp
	
clean:
	-rm mcalc $(OBJECTS)

debug: main
	@valgrind $(VOPT) ./mcalc