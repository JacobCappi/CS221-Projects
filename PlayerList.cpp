#include "PlayerList.h"
// -- PlayerList Basic Node Linked List methods (inspiration from DateList.cpp)

/* ------------------------------------------
Node(const Player) - Default Node constructor
------------------------------------------ */ 
Node::Node(const Player& playerItem) { // Our beautiful doubly linked node
    m_item = playerItem;
    p_Next = NULL; // default is grounded to Null
    p_Before = NULL;
}
/* ------------------------------------------
PlayerList() - Default PlayerList Constructor
------------------------------------------ */ 
PlayerList::PlayerList() { // Basic init with pointers set to Null
    m_length = 0;
    p_First = NULL;
}

/* ------------------------------------------
isEmpty() - returns whether List is Empty
------------------------------------------ */ 
bool PlayerList::isEmpty() { // Self explanatory
    return(p_First == NULL);
}

/* ------------------------------------------
PlayerList() - Returns whether List is Full
------------------------------------------ */ 
bool PlayerList::isFull() {
    return(false); // NodeList probably isn't ever going to be completely filled
}

/* ------------------------------------------
getSize() - returns the length of the List
------------------------------------------ */ 
int PlayerList::getSize() {
    return(m_length);
}

/* ------------------------------------------
clear() - clears the list back to init state
------------------------------------------ */ 
void PlayerList::clear() {
    Node* tempPtr; // the pointer that is going to help us iterate through and kill every node

    while (p_First != NULL) { // Moves the p_Next to the next pointer and kills the original until all are deleted 
        tempPtr = p_First;
        p_First = p_First->p_Next;
        delete tempPtr;
    }
    m_length = 0;
}
/* ------------------------------------------
~PlayerList() - Basic Deconstructor running clear
------------------------------------------ */ 
PlayerList::~PlayerList() {
    clear(); // just runs our deleter upon not existing
}

/* ------------------------------------------
add(Player) - adds player to doubly linked list
------------------------------------------ */ 
void PlayerList::add(Player playerItem) { // code literally acts like I'm connecting cables...
    Node *p_Node, *p, *q; // so just think of the pointers as cables and it makes sense
    p_Node = new Node(playerItem);

    p = p_First;
    q = NULL;

    while(p != NULL){
        if(p->m_item > playerItem){   
            break;
        } else{
            q = p;
            p = p->p_Next;
        }
        
    }

    p_Node->p_Next = p;
    p_Node->p_Before = q;
    
    if(q == NULL){
        p_First = p_Node;
    } else if(p == NULL){
        q->p_Next = p_Node;
    } else{
        p->p_Before = p_Node;
        q->p_Next = p_Node;  
    }
    m_length++;
    return;

}

/* ------------------------------------------
remove(Player) - removes player in doubly linked list
------------------------------------------ */ 
bool PlayerList::remove(Player playerItem){ //Same as 'add', fairly easy to understand if
    Node *p, *q; // I can try an picture it (~_~);
    bool retVal = false;

    p = p_First;
    q = NULL;

    while(p != NULL){
        if(p->m_item == playerItem){
            retVal = true;
            break;
        } else{
            q = p;
            p = p->p_Next;
        }
    }
    
    if(retVal){
        if (q != NULL){
            q->p_Next = p->p_Next;
            p->p_Next->p_Before = q;
        } else{
            p_First = p->p_Next;
            p_First->p_Before = NULL;
        }
        delete p;
        m_length--;
    }
    
    return retVal;
}


// Finally iterator methods

/* ------------------------------------------
resetToStart() - resets to beginning of list
------------------------------------------ */ 
void PlayerList::resetToStart() {
    p_Current = p_First; // moves us back to the beginning
}

/* ------------------------------------------
hasNext() - Checks if next Node exists
------------------------------------------ */ 
bool PlayerList::hasNext() {
    return(p_Current != NULL); // if we moved to Void, then the pointer we were on was pointing to void
}

/* ------------------------------------------
getNext() - get's next player in list
------------------------------------------ */ 
Player PlayerList::getNext() { // our main iterator
    Player tempPlayer;

    if (hasNext()) {
        tempPlayer = p_Current->m_item; // Become this Player
        p_Current = p_Current->p_Next; // go to the next Player
    }

    return tempPlayer; // send current Player
}

/* ------------------------------------------
dump(stream) - dumps everything in node 
        unformatted into stream
------------------------------------------ */ 
void PlayerList::dump(ostream& o) {
    Node* tempPlayer = p_First;
    while (tempPlayer) { // Basic pointer that shifts through everything and dumps it
        tempPlayer->m_item.printStats(o);
        tempPlayer = tempPlayer->p_Next;
    }
}
/* ------------------------------------------
dumpdump(stream) - dumps the dump backwords
        (>_>)! not sure why I named it that
------------------------------------------ */ 
void PlayerList::dumpdump(ostream &o){
    Node* tempPlayer = p_First;
    while(tempPlayer->p_Next != NULL){
        tempPlayer = tempPlayer->p_Next;
    }
    while(tempPlayer->p_Before != NULL){
        tempPlayer->m_item.printStats(o);
        tempPlayer = tempPlayer->p_Before;
    }
    tempPlayer->m_item.printStats(o);
}

//-- End of Basic PlayerList methods

// -- Program Specific Methods

// Repurposed dump function
/* ------------------------------------------
teamBattingAvg() - p2 stats  for a more 
        useful  dump
------------------------------------------ */ 
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

/* ------------------------------------------
printToOutputFile() - a prettier dump for 
        output formatting
------------------------------------------ */ 
void PlayerList::printToOutputFile(ostream& o) { // more formatting that took as long as the code...
// still doesn't look 'good' but it seems to work
    o << "Baseball Team Report \n\nSize: " << getSize() << "\nOverall Batting AVG: " << setprecision(4) << teamBattingAvg() << "\n\n\n";
    o << setw(21) << "Name : ";
    o << setw(15) << "Bat AVG   OBS" << endl;
    o << "------------------------------------" << endl;
}

