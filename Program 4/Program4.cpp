/*
***************************************************************************
* Assignment: Baseball player Batting Data + Stats
* Name: Program4.cpp
*
* IDE : Written in VS code (Ubuntu), g++ compiler, makefile included
* Run : Make (make clean if make exists), then ./main
* Author: jc0199@uah.edu (Jacob Cappi)
* Created: 14 Novemeber 2020
*
* Use:  Accept a text file and harvest it's info
*       Stores all information in the form of Player into the PlayerList class,
*       Sends name, batting avg, and OBS to outfile in order
*       Couts information in reverse order
*
***************************************************************************
*/

#include "PlayerList.h"

#include <fstream>

using namespace std;

int main() {

    PlayerList baseballPlayers; // The list object
    Player tmpPlayer; // our tmp player to copy info into the list

    // basic fstream variables
    string inputFileName; 
    string outFileName;

    ifstream inputFile;
    ofstream outFile;

    
     cout << "Welcome to the player statistics calculator test program. \nI am going to read players from an input data file. \nYou will tell me the names of your input and output files. \nI will store all of the players in a list, compute each player's averages \nand then write the resulting team report to your output file.\n" << endl;
     cout << "Enter the name of your input file: ";
     cin >> inputFileName;
     cout << "Enter the name of your output file: ";
     cin >> outFileName;
     

    inputFile.open(inputFileName);
    outFile.open(outFileName);

    // Basic error checking
    if (inputFile.fail()) {
        cout << "error, invalid name" << endl;
        return -1;
    }

    cout << "\n\nReading from file: " << inputFileName << endl;

    while (!inputFile.eof()) {
        tmpPlayer.reader(inputFile); // reading 1 Player's worth from the file
        baseballPlayers.insert(tmpPlayer); // adding 1 Player as a node item into linked list
    }

    baseballPlayers.printHeader(outFile);
    baseballPlayers.printInOrder(outFile);

    baseballPlayers.printHeader(std::cout);
    baseballPlayers.printReverseOrder(std::cout);    

}