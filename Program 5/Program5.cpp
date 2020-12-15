/*
***************************************************************************
* Assignment: Merge Sort
* Name: Program5.cpp [requires Program5_functions.h and Players.h]
*
* IDE : Written in VS code (Ubuntu), g++ compiler, makefile included
* Run : Make (make clean if make exists), then ./main
* Author: jc0199@uah.edu (Jacob Cappi)
* Created: 3 December 2020
*
* Use:  Accept a text file and harvest it's info
*       Stores all information in the form of Player into the PlayerList array,
*       Merge Sorts and ouputs into file
*
***************************************************************************
*/


#include "Program5_Functions.h"

#define MAX 100
#define BAR "\n--------------------------------------\n"

using namespace std;

int main(){

    // just an all purpose counter variable
    int counter = 0;

    Player playerList[MAX];
    ifstream inputFile;
    ofstream outputFile;
    string inputFileName, outputFileName;

    cout << "Welcome to the player statistics calculator test program. \nI am going to read players from an input data file. \nYou will tell me the names of your input and output files. \nI will store all of the players in a list, and sort it \nand then write the resulting team report to your output file.\n" << endl;

    cout << "\nName of input file: ";
    cin >> inputFileName;
    cout << "\nName of output file: ";
    cin >> outputFileName;
    

    inputFile.open(inputFileName);
    outputFile.open(outputFileName);

    if (inputFile.fail()) {
        cout << "Error: invalid name" << endl;
        return -1;
    }


    counter = inputData(playerList, MAX, inputFile);
    
    outputFile << "Player Report: " << counter << " Players in File\n\n";
    outputFile << "    PLAYER NAME     |   AVERAGE   OPS";
    outputFile << BAR;

    for(int i=0; i<counter; i++){playerList[i].printToOutputFile(outputFile);}

    mergeSort(playerList, 0, counter);

    outputFile << BAR;
    outputFile << "Sorted:\n\n";
    outputFile << "    PLAYER NAME     |   AVERAGE   OPS";
    outputFile << BAR;
    for(int i=0; i<counter; i++){playerList[i].printToOutputFile(outputFile);}


    return 0;
}