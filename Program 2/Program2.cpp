/*
***************************************************************************
* Assignment: Baseball player Batting Data + Stats
* Name: Program2.cpp
*
* IDE : Written in VS code, default compiler for VS 2019 (Cl)
* Author: jc0199@uah.edu (Jacob Cappi)
* Created: 26 Sept 2020
*
* Use:  Accept a text file and harvest it's info
*       Stores all information in the form of Player into the PlayerList class,
*       Sends name, batting avg, and OBS to outfile
*
***************************************************************************
*/


#include <iostream>
#include <fstream>
#include <string>

#include "PlayerList.h"

int main() {
    using namespace std;

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
        baseballPlayers.add(tmpPlayer); // adding 1 Player as a node item into linked list
    }

    baseballPlayers.printToOutputFile(outFile); // Formatting method I created to help declutter main()
    baseballPlayers.resetToStart(); // incase the pointer moved for some reason

    while (baseballPlayers.hasNext()) { // Basic method to check if pointer is Null;
        tmpPlayer = baseballPlayers.getNext(); // stores item into tmpPlayer and moves on
        tmpPlayer.printToOutputFile(outFile); // sends that to the file
    }


    cout << "Completed writing to output file: " << outFileName<< "\n\nEnd of Program 2" << endl;

    inputFile.close(); // closing the streams
    outFile.close();
    return 0;


}