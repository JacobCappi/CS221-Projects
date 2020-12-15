
#include <iostream>
#include <string>

#include "Player.cpp"
using namespace std;

class Node {
public:
    Player m_item;		 // storage space for a Date
    Node* p_Next;		// a pointer to the next dynamically allocated Node in the list
    Node* p_Before;    // second pointer to the one before to be doubly linked (I think)
    Node(const Player& dateIn);  // used to copy date into newly created nodes for our list
};

class PlayerList {
private:
    // p_First to know where the beginning is, P_Last to know where the last node is
    Node* p_First, * p_Current; // p_First for the root, p_Current for iteration
    int m_length; // Just useful to know the size of the list

public:
    // default constructors and destructor
    PlayerList();
    ~PlayerList();

    // Observers of the condition of the List (fairly self explanatory)
    bool isEmpty();
    bool isFull();
    int  getSize();

    // Utility Transformers
    void clear(); // Clears our list
    void add(Player playerItem); // Adds a new Player to the end of the list
    bool remove(Player playerItem); //Removes a new Player


    // Useful Iterorator neccassary methods 
    void resetToStart();   // sets the list iterator to the start of the list
    bool hasNext();        // true if the iterator has another item to return
    Player getNext();        // returns the next item from the list when iterating

    // the dumper
    void dump(ostream& o);  // dumps a list to an output stream;
    void dumpdump(ostream &o); // dumps a list from the back; 

    // the Program Specific method
    float teamBattingAvg(); // Calculate avg;
    // Print to output File
    void printToOutputFile(ostream& o); // another formatting method
};