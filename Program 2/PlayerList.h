
#include <iostream>
#include <string>
#include "Player.h"
using namespace std;

class Node {
public:
    Player m_item;			// storage space for a Date
    Node* p_Next;		// a pointer to the next dynamically allocated Node in the list
    Node(const Player& dateIn);  // used to copy date into newly created nodes for our list
};

class PlayerList {
private:
    // p_First to know where the beginning is, P_Last to know where the last node is
    Node* p_First, * p_Last, * p_Current; // p_Current added Later for iterations
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


    // Useful Iterorator neccassary methods 
    void resetToStart();   // sets the list iterator to the start of the list
    bool hasNext();        // true if the iterator has another item to return
    Player getNext();        // returns the next item from the list when iterating

    // the dumper
    void dump(ostream& o);  // dumps a list to an output stream;

    // the Program Specific method
    float teamBattingAvg(); // Calculate avg;
    // Print to output File
    void printToOutputFile(ostream& o); // another formatting method
};