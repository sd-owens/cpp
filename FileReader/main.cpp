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
#include "fileReader.hpp"
#include "Menu.hpp"

/*
 * Summary: Main function which provides input prompt strings for the generic Menu class,
 *          initializes the name of the input file as provided by the user in the Menu
 *          and provides main while loop for the file reader program.
 * Param: none
 * Returns: int which is a 0 for successful program execution, anything else is an error.
 */
int main(){

    std::string title = "\n***************************************************************\n"
                        "************************** FileReader *************************\n"
                        "***************************************************************\n\n"
                        "This program reads in a user specified filename and creates an \n"
                        "output file name \"output.txt\" that holds the frequency of the\n"
                        "occurrences of each letter in the input file\n";

    std::string mainMenu = "\nChoose an option:\n\n"
                           "1. Start Reader!\n2. Quit\n";

    std::string subMenu1 = "\n---------------------------------------------------------------\n"
                           "|Note: Input file must be in same directory as this executable|\n"
                           "|or the relative path must be provided \"../input.txt\"  [UNIX] |\n"
                           "|for a file in the parent directory (or \"..\\input.txt\\\" [WIN].|\n"
                           "---------------------------------------------------------------\n";
//            "\nSome information is required before we begin the simulation:\n";

    std::string inputPrompts = "\nEnter the name of the input file: \n";

    std::string startPrompt = "\nReady to read the file?\n"
                              "1. Start\n2. Quit\n3. Re-enter input file name\n";

    std::string replayPrompt = "\nOperation Complete!\n"
                               "\nRead another file?\n"
                               "1. Yes\n2. Quit\n";

    std::string fileName{};
    int replayChoice {};

    Menu m (title, mainMenu, subMenu1, inputPrompts, startPrompt, replayPrompt );

    fileName = m.display();

    if (fileName.empty()) {
        std::cerr << "\nUser aborted or file name was empty, exiting..." << std::endl;
    } else {

        while (!fileName.empty()) {
            run(fileName);
            replayChoice = m.replay();
            fileName = m.display(replayChoice);
            if (fileName.empty()) {
                std::cerr << "User aborted or file name was empty, exiting..." << std::endl;
            }
        }
    }

    return 0;
}