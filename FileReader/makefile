#/**************************************************************************************
# * Program name: File Reader
# * Author: Steven Owens
# * Date: 10/11/2019
# * Description:  File Reader is a program that reads in an input file as specified
# *               by the user and counts the occurrence of each letter from the English
# *               alphabet. The program then outputs the frequency of each letter
# *               occurrence as a separate output file named output.txt in the same
# *               directory as the binary executable. Note, the input file should be
# *               located in the same directory as the binary executable or the relative
# *               path to the file must be specified as part of the file name.  For
# *               instance, input.txt  in a directory one level above the binary would
# *               be specified as "../input.txt" signifying it resides in the parent
# *               directory.  As prompt is provided to the user to distinguish the
# *               actions required on either a UNIX (Mac or Linux) or a Windows OS.
#  ************************************************************************************/

# makefile syntax adapted from example provided TA Harlan James <waldroha@oregonstat.edu>

# Project Name
PROJ = fileReader

# Compiler
CXX = g++

# Compiler C++ Version
CXXVER = -std=c++11

# Compiler Flags
CXXFLAGS = -Wall -g

# Source Files
SRC = main.cpp
SRC += fileReader.cpp Menu.cpp validInput.cpp

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
	@echo "CC       $@"
	@$(CXX) $(CFLAGS) $^ -o $@

# % is a wildcard. Anything that ends in ".o" will match this tag, and each
# tag depends on the same matching wildcard, but ending in ".cpp"
%.o: %.cpp
	@echo "CC       $^"
	@$(CXX) $(CXXVER) $(CFLAGS) -c $^

zip:
	zip $(PROJ).zip *.cpp *.hpp makefile

clean: $(CLEAN)
	@echo "RM       *.o"
	@echo "RM       $(BIN)"
	@rm -f *.o $(BIN)


