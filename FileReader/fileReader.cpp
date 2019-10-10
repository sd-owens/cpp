//
// Created by steve on 10/9/19.
//

#include <fstream>
#include <iostream>
#include "fileReader.hpp"


void count_letters(std::ifstream & inputFile, int * letterFreq) {

    const char letter = 'A';  // ascii code 65;
    char temp {};  // temp variable to hold char while iterating through lines string.
    int index {};  // index from the result of 'char' subtraction for letterFreq []

    std::string words;
    std::string lines;

    inputFile.open("../file_fun.txt");

    if(inputFile) {

        while (inputFile >> words) {

            lines += words;
        }
    } else {
        std::cout << "File could not be found and opened" << std::endl;
    }

    for (int i = 0; i < lines.length(); i++){

        if (std::isalpha(lines.at(i))){
            temp = std::toupper(lines.at(i));

            index = temp - letter;

            letterFreq[index]++;
        }
    }

    inputFile.close();
}

void output_letters(std::ofstream & outputFile, int * letterFreq) {

        char letter = 'A';

        outputFile.open("../output.txt");

        for(int i = 0; i < 26; i++) {
            outputFile << static_cast<char>(letter + i);
            outputFile << ": " << std::to_string(letterFreq[i]) + "\n";
        }
        outputFile.close();
}
