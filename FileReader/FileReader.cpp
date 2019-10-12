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
#include <string>
#include <fstream>
#include <iostream>
#include "FileReader.hpp"
/*
 * Summary: Constructor for the file reader class which sets its pointer to a menu
 *          object to the object passed in during instantiation and intializes its
 *          private member variable strings to empty strings.
 * Param: A pointer to the object of type Menu.
 * Returns: void
 */

FileReader::FileReader(Menu* menu) {
    this->menu = menu;
    this->fileName = "";
    this->outputName = "";
}
/*
 * Summary: Provides overall logic for the FileReader class to setup conditions before
 *          program open and reads an input filestream.  Ensures valid filenames exist
 *          (which are stored as private variables of the instance) and provides error
 *          handling for opening files.  Also provide replay functionality to reach in
 *          additional files after completing operations.
 *
 * Param: none
 * Returns: void
 */
void FileReader::run(){

    std::ifstream ifs;
    int replayChoice;
    // initialize an array of 26 integers to 0, one for each letter of English Alphabet
    int letterFreq[26] {0};

    this->fileName = menu->inputMenu();

    if (fileName.empty()) {

        std::cerr << "\nUser aborted or file name was empty, exiting..." << std::endl;

    } else {

        while (!fileName.empty()) {

            ifs.open(this->fileName);
            count_letters(ifs, letterFreq);
            ifs.close();
            replayChoice = menu->replayMenu();
            fileName = menu->inputMenu(replayChoice);

            if (fileName.empty()) {
                std::cerr << "User aborted or file name was empty, exiting..." << std::endl;
            }
        }

    }
}
/*
 * Summary: Resets the letter frequency array to all zeros (26 zeros) to re-initialize
 *          the array for the next pass of the main while loop in the run function.
 * Param: A pointer to the array of integers letterFreq.
 * Returns: void
 */
void FileReader::resetCount(int * letterFreq){
    for (int i = 0; i < 26; i++){
        letterFreq[i] = 0;
    }
}
/*
 * Summary: Reads in the input file stream to the string "lines" using the default
 *          delimiter newline ('\n').  Each iteration of the while loop readers in an
 *          entire paragraph and the while loop continues until getline reaches the EOF
 *          marker.  The function iterates over the entire "lines" string converting
 *          the contents to all uppercase letters and checking if they are characters
 *          of the alphabet and if true, increments their respective index in the
 *          letterFreq array.  Finally, once the for loop exits, the output_letters
 *          function is called and letter frequency array is reset to all zeros.
 * Param: std::ifstream and a pointer to the array of integers letterFreq.
 * Returns: void
 */
void FileReader::count_letters(std::ifstream& ifs, int * letterFreq){
    const char letter = 'A';  // ascii code 65;
    int index {};  // index from the result of 'char' subtraction for letterFreq []
    std::ofstream ofs;
    // true if file exists and permissions allow opening
    if(ifs) {

        std::string lines;

        while (getline(ifs, lines)) {

            char temp {};  // temp variable to hold char while iterating through lines string.

            for(int i = 0; i < lines.length(); i++) {

                if (std::isalpha(lines.at(i))){

                    temp = std::toupper(lines.at(i));

                    // uses char arithmetic based off the 'A" ascii code of 65 to determine index.
                    index = temp - letter;

                    letterFreq[index]++;
                }
            }
            this->outputName = menu->outputMenu();
            output_letters(ofs, letterFreq);
            resetCount(letterFreq);
        }

    } else {

        std::cout << "Input file could not be found and opened\n"
                     "Please check spelling and/or path syntax" << std::endl;
    }
}
/*
 * Summary: Outputs the letter frequency array to an output file named as specified
 *          by the user. Uses char arithmetic based on the ascii code for 'A' of 65
 *          to create a label for each integer value held in the letterFreq array.
 *          A separate output file is generated for each call.
 * Param: std::ofstream and a pointer to the array of integers letterFreq.
 * Returns: void
 */
void FileReader::output_letters(std::ofstream & ofs, int* letterFreq){
    char letter = 'A';

    if(ofs) {
        ofs.open(this->outputName);

        for(int i = 0; i < 26; i++) {
            ofs << static_cast<char>(letter + i);
            ofs << ": " << std::to_string(letterFreq[i]) + "\n";
        }
        ofs.close();

    } else {

        std::cout << "Output file could not be found and opened\n"
                     "Please check spelling and/or path syntax" << std::endl;

    }
}