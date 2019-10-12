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
**************************************************************************************/
#include <iostream>
#include <string>
#include "Menu.hpp"
#include "validInput.hpp"
/*
 * Summary: Menu constructor which takes numerous input parameters passed by reference
 *          to prevent duplicating strings in memory.  Each input param is initialized
 *          to its respective private instance variable.
 * Param: 8 strings for menu Prompts for data prompts. By passing in params in this
 *        manner I have attempted to encapsulate the Menu class for future use a
 *        generic user input Menu.
 * Returns: N/A
 */
Menu::Menu(std::string &title, std::string &mainMenu, std::string &subMenu1, std::string &inputPrompts, std::string &startPrompt, std::string &relayPrompt, std::string &outputPrompt1, std::string &outputPrompt2) {
    this->title = title;
    this->mainMenu = mainMenu;
    this->subMenu1 = subMenu1;
    this->inputPrompts = inputPrompts;
    this->startPrompt = startPrompt;
    this->replayPrompt = relayPrompt;
    this->outputPrompt1 = outputPrompt1;
    this->outputPrompt2 = outputPrompt2;
    this->replayFlag = false;
}
/*
 * Summary: Primary method for user input, handles all logic and console prompts to facilitate user input
 *          and validation of entry of only positive integer values.
 * Param: int choice which by default is 0 from hpp definition, this allows passing in a value for the replay
 *        functionality.
 * Returns: std::string which is the name of the input file for the file reader.
 */
std::string Menu::inputMenu(int choice) {

    /* static variable to track the number of times a Menu object is created for use in user replay feature.*/
    static unsigned int count;
    std::string inputMenu1, inputMenu2, inputMenu3 {};
    int choiceMenu1 = choice;
    int choiceMenu3 {};

    std::string fileName;

    do {
        if(count == 0) {
            std::cout << title;
            std::cout << mainMenu;

            while(choiceMenu1 != 1 && choiceMenu1 != 2) {
                getline(std::cin, inputMenu1);
                choiceMenu1 = validateInput(inputMenu1);
                if(choiceMenu1 != 1 && choiceMenu1 != 2){
                    std::cerr << "Pick 1 or 2!\n";
                }
            }
        }

        if(choiceMenu1 == 2 || choiceMenu3 == 2) {
            fileName = "";  // return an empty string to main
            return fileName;

        } else if(choiceMenu1 == 1 || choiceMenu3 == 3) {

            if(count == 0) {
                std::cout << subMenu1;
            }

            std::cout << inputPrompts;
            getline(std::cin, inputMenu2);
            fileName = inputMenu2;

        }
        count++;
        std::cout << startPrompt;

        choiceMenu3 = 0; //reset choice menu 3 to 0 prior to entering loop.

        while(choiceMenu3 != 1 && choiceMenu3 != 2 && choiceMenu3 != 3) {
            getline(std::cin, inputMenu3);
            choiceMenu3 = validateInput(inputMenu3);
            if(choiceMenu3 != 1 && choiceMenu3 != 2 && choiceMenu3 != 3){
                std::cerr << "Pick 1, 2, or 3!\n";
            }
        }

        if(choiceMenu3 == 1) {
            return fileName;
        }

    } while (true);
}
/*
 * Summary: Replay function which displays a replayMenu to the user and captures their choice.
 * Param: none
 * Returns: int which is a 1 or 2 by the menu.
 */
int Menu::replayMenu() {

    this->replayFlag = true;

    std::string inputMenu4 {};
    int choice {};

    std::cout << replayPrompt;
    while(choice != 1 && choice != 2) {
        getline(std::cin, inputMenu4);
        choice = validateInput(inputMenu4);
        if(choice != 1 && choice != 2){
            std::cerr << "Pick 1 or 2!\n";
        }
    }

    return choice;
}
/*
 * Summary: OutputMenu function which displays a menu to the user and captures their choice. Uses a static
 *          local variable to track number of calls to update paragraph number in console prompt.
 * Param: none
 * Returns: std::string output file name
 */
std::string Menu::outputMenu(){
    /* static variable to track outputMenu calls for custom outputPrompt.*/
    static unsigned int count = 1;
    if(this->replayFlag){
        resetStatic(count);  //resets static counter to 1 since a true replayFlag means a new file is being read.
        this->replayFlag = false;
    }
    std::string inputMenu5;
    if(count == 1){
        std::cout << outputPrompt1 << std::endl;
    }
    std::cout << outputPrompt2 + "Paragraph (" + std::to_string(count) + "): \n";
    getline(std::cin, inputMenu5);
    count++;
    return inputMenu5;
}

unsigned int Menu::resetStatic(unsigned int& count) {
    count = 1;
    return count;
}
