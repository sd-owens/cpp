#/************************************************************************
#** Program name: Matrix Determinant Caculator
#** Author: Steven Owens
#** Date: 9/29/2019
#** Description:  Program to calculate the determinant of a matrix of size
#** 2x2 or 3x3. Provides functionality for user to choose size of matrix
#** and input integer data with error handling to prevent input of invalid
#** data and safeguard againgst erroneous results.  This program should be
#** compiled with the command "make" from the command line which produces
#** an executable named "mcalc.bin". Run with the command ./mcalc.bin
#************************************************************************/

# makefile syntax adapted from example provided TA Harlan James <waldroha@oregonstat.edu> 

# Project Name
PROJ = mcalc

# Compiler
CXX = g++

# Compiler C++ Version
CXXVER = -std=c++11

# Compiler Flags
CXXFLAGS = -Wall -g

# Source Files
SRC = main.cpp
SRC += determinant.cpp readMatrix.cpp

# Create an object for each source file
OBJ = $(SRC:.cpp=.o)

# Output Binary
BIN = $(PROJ).bin

# Valgrind Options
VOPT = --tool=memcheck --leak-check=full --show-leak-kinds=all --track-origins=yes

# Names of tags that aren't actually files. Without this, if there were ever a
# file in the directory with these names they would never run.
#
# Why? Because Make is checking to see if these files exist. If they already do
# it skips them!
.PHONY: default debug clean zip

# Default Behavior:
#     1. Remove everything to start from screatch
#     2. Compile the binary
#     3. Run it through valgrind for quicker debugging
#
default: clean $(BIN) #debug

# Order assuming no files exist:
#     1. Each .o file
#     2. Binary
#     3. Valgrind
# 
# Special Symbols:
#     @     Suppresses the command from being printed to the terminal)
#     $@    Name of tag
#     $^    Name of dependency
debug: $(BIN)
	@valgrind $(VOPT) ./$(BIN)

$(BIN): $(OBJ)
	@echo "CC	$@"
	@$(CXX) $(CFLAGS) $^ -o $@

# % is a wildcard. Anything that ends in ".o" will match this tag, and each
# tag depends on the same matching wildcard, but ending in ".cpp"
%.o: %.cpp
	@echo "CC	$^"
	@$(CXX) $(CXXVER) $(CFLAGS) -c $^

zip:
	zip $(PROJ).zip *.cpp *.hpp makefile

clean: $(CLEAN)
	@echo "RM	*.o"
	@echo "RM	$(BIN)"
	@rm -f *.o $(BIN)