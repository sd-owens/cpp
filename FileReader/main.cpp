
#include <iostream>
#include "fileReader.hpp"
#include "Menu.hpp"

int main(){

    std::string title = "\n****************************************************\n"
                        "********************* FileReader *******************\n"
                        "****************************************************\n\n"
                        "This program reads in a user specified filename and \n"
                        "creates an output file name \"output.txt\" that holds\n"
                        "the frequency of the occurrence of each letter in the\n"
                        "input file.\n";

    std::string mainMenu = "\nChoose an option:\n\n"
                           "1. Start Reader!\n2. Quit\n";

    std::string subMenu1 = "\n(Note: input file must be in same directory as this executable)\n";
//            "\nSome information is required before we begin the simulation:\n";

    std::string inputPrompts = "\nEnter the name of the input file\n";

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