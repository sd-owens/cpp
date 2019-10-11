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
#include <iostream>
#include <string>
/*
 * Summary: Provides user input validation by iterating through string and checks if
            all char are digits, if not it sets the isValidInput flag to false and
            breaks the loop since a single since a single failed check means the input
            is invalid.
 * Param: std::string input
 * Returns: bool - true if valid or false if not.
 */
bool isValid(std::string input) {

    bool validInput = true;

    for(unsigned int i = 0; i < input.length(); i++){

        if(!std::isdigit(input.at(i))){
            validInput = false;
            break;
        }
    }

    return validInput;
}
/*
 * Summary: Validates and provides error handling for user input as a string and returns
 *          a fully qualified integer value back to the calling function. Prompts user
            for input following validation failure.
 * Param: std::string input
 * Returns: integer which is validated and converted from a std::string.
 */

/*  cin methods fail, ignore, and cerr adapted from a post by user "int main" on
    20080715 from http://www.cplusplus.com/forum/beginner/2957/ Elected to not use
    cin.fail() and use string input for validation */
int validateInput(std::string input){

    while(input.empty() || !isValid(input)){

        //clears potential error flag on cin from invalid input.
        std::cerr << "Must enter an integer!\n";
        std::cin.clear();
        input = "";  // re-initializes input to empty string ""

        getline(std::cin, input);

    }

    return std::stoi(input);
}