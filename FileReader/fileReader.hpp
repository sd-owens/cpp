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

#ifndef FILEREADER_HPP
#define FILEREADER_HPP

// function prototypes
void run(std::string& fileName, std::string& outputName);
void resetCount(int * letterFreq);
void count_letters(std::ifstream &, int*);
void output_letters(std::ofstream &, int*);



#endif //FILEREADER_HPP
