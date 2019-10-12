/**************************************************************************************
* Program name: File Reader
* Author: Steven Owens
* Date: 10/11/2019
* Description:  File Reader is a program that reads in an input file as specified
*               by the user and counts the occurrence of each letter from the English
*               alphabet. The program then outputs the frequency of each letter
*               occurrence as a separate output file named output.txt in the same
*               directory as the binary executable. Note, the input file should be
*               located in the same directory as the binary executable or the relative
*               path to the file must be specified as part of the file name.  For
*               instance, input.txt  in a directory one level above the binary would
*               be specified as "../input.txt" signifying it resides in the parent
*               directory.  As prompt is provided to the user to distinguish the
*               actions required on either a UNIX (Mac or Linux) or a Windows OS.
*************************************************************************************/

#include <fstream>
#include <iostream>
#include "fileReader.hpp"
#include "Menu.hpp"
/*
 * Summary: Sets up File Reader function by initializing input and output file
 *          streams and an array of integers for recording letter frequencies.
 * Param: std::string which is the input file name passed by reference from main.cpp
 * Returns: void
 */
void run(std::string& fileName, std::string& outputName) {

    std::ifstream inputFile;

    inputFile.open(fileName);

    // initialize an array of 26 integers to 0, one for each letter of English Alphabet
    int letterFreq[26] {0};

    count_letters(inputFile, letterFreq);

}
/*
 * Summary: Reads in the input file stream to the string "words" and concatenates each
 *          successful read (up to a whitespace character or until its reaches the EOF
 *          marker) onto the "lines" array which holds the completes contents of the file.
 *          The function iterates over the entire "lines" string converting the contents
 *          to all uppercase letters and checking if they are characters of the alphabet
 *          and if true, increments their respective index in the letterFreq array.
 * Param: std::ifstream and a pointer to the array of integers letterFreq.
 * Returns: void
 */
void count_letters(std::ifstream & inputFile, int * letterFreq) {

    const char letter = 'A';  // ascii code 65;
    std::ofstream outputFile;
    int index {};  // index from the result of 'char' subtraction for letterFreq []

    // true if file exists and permissions allow opening
    if(inputFile) {

        std::string words;

        while (inputFile >> words) {

            char temp {};  // temp variable to hold char while iterating through lines string.

                for(int i = 0; i < words.length(); i++) {

                    if (words.at(i) == '\n'){
                        output_letters(outputFile, letterFreq);
                        break;
                    }

                    if (std::isalpha(words.at(i))){

                        temp = std::toupper(words.at(i));

                        // uses char arithmetic based off the 'A" ascii code of 65 to determine index.
                        index = temp - letter;

                        letterFreq[index]++;
                    }
                }
                resetCount(letterFreq);
        }

    } else {

        std::cout << "File could not be found and opened" << std::endl;
    }

    inputFile.close();
}
/*
 * Summary: Outputs the letter frequency array to an output file named output.txt.  Uses
 *          char arithmetic based on the ascii code for 'A' of 65 to create a label for
 *          each integer value held in the letterFreq array.
 *
 * Param: std::ofstream and a pointer to the array of integers letterFreq.
 * Returns: void
 */
void output_letters(std::ofstream & outputFile, int * letterFreq) {

        char letter = 'A';

        outputFile.open("../output.txt");

        for(int i = 0; i < 26; i++) {
            outputFile << static_cast<char>(letter + i);
            outputFile << ": " << std::to_string(letterFreq[i]) + "\n";
        }
        outputFile.close();
}
/*
 * Summary: Resets the letter frequency array to 26 zeros.
 * Param:  Pointer to the array of integers letterFreq.
 * Returns: void
 */
void resetCount(int * letterFreq){

    for (int i = 0; i < 26; i++){
        letterFreq[i] = 0;
    }
}
