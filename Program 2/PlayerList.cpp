#include "PlayerList.h"
// -- PlayerList Basic Node Linked List methods (inspiration from DateList.cpp)

Node::Node(const Player& playerItem) { // Our beautiful single linked node
    m_item = playerItem;
    p_Next = NULL; // default is grounded to Null
}

PlayerList::PlayerList() { // Basic init with pointers set to Null
    m_length = 0;
    p_First = NULL;
    p_Last = NULL;
}


bool PlayerList::isEmpty() { // Self explanatory
    return(p_First == NULL);
}

bool PlayerList::isFull() {
    return(false); // NodeList probably isn't ever going to be completely filled
}

int PlayerList::getSize() {
    return(m_length);
}

void PlayerList::clear() {
    Node* tempPtr; // the pointer that is going to help us iterate through and kill every node

    while (p_First != NULL) { // Moves the p_Next to the next pointer and kills the original until all are deleted 
        tempPtr = p_First;
        p_First = p_First->p_Next;
        delete tempPtr;
    }
    p_Last = NULL; // at this point, there are no more nodes, so reset this pointer as well.
    m_length = 0;
}

// Waited to build clear() for deconstructor
PlayerList::~PlayerList() {
    clear(); // just runs our deleter upon not existing
}


void PlayerList::add(Player playerItem) {
    // Creating an adress to a Node then throwing a Node into our memory pool
    Node* tempPtr;
    tempPtr = new Node(playerItem);

    // Bureaucratic Pointer manip
    if (isEmpty()) {
        p_First = tempPtr; // If first in list, address get's started
    }
    else {
        p_Last->p_Next = tempPtr; // if not first, the last one's ptr points to this
    }
    p_Last = tempPtr; // increment our new last (this p_Last is pointing to Null)
    m_length++; // size increment
}


// Finally iterator methods
void PlayerList::resetToStart() {
    p_Current = p_First; // moves us back to the beginning
}

bool PlayerList::hasNext() {
    return(p_Current != NULL); // if we moved to Void, then the pointer we were on was pointing to void
}
Player PlayerList::getNext() { // our main iterator
    Player tempPlayer;

    if (hasNext()) {
        tempPlayer = p_Current->m_item; // Become this Player
        p_Current = p_Current->p_Next; // go to the next Player
    }

    return tempPlayer; // send current Player
}

void PlayerList::dump(ostream& o) {
    Node* tempPlayer = p_First;
    while (tempPlayer) { // Basic pointer that shifts through everything and dumps it
        tempPlayer->m_item.printStats(o);
        tempPlayer = tempPlayer->p_Next;
    }
}
//-- End of Basic PlayerList methods

// -- Program Specific Methods

// Repurposed dump function
float PlayerList::teamBattingAvg() {
    Node* tempPlayer = p_First;
    float retVal = 0.0;

    while (tempPlayer) { // method being called is dif to serve that function
        retVal += tempPlayer->m_item.getBattingAvg();
        tempPlayer = tempPlayer->p_Next;
    }

    return (retVal / (float)m_length);
}

// output file reporting

void PlayerList::printToOutputFile(ostream& o) { // more formatting that took as long as the code...
// still doesn't look 'good' but it seems to work
    o << "Baseball Team Report \n\nSize: " << getSize() << "\nOverall Batting AVG: " << setprecision(4) << teamBattingAvg() << "\n\n\n";
    o << setw(21) << "Name : ";
    o << setw(15) << "Bat AVG   OBS" << endl;
    o << "------------------------------------" << endl;
}