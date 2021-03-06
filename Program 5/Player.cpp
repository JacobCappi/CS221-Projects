/*
***************************************************************************
* Assignment: Merge Sort
* Name: Player.cpp [requires Players.h]
*
* Use:  Contains "Player" class and all methods
*       Mainly gets and convience methods like reader and print
*       Overloads operators : '<' '>' and '=='
*       The code is written here
*
***************************************************************************
*/



#include "Player.h"

using namespace std;

/* ------------------------------------------
Player() - default Constructor
------------------------------------------ */ 
Player::Player() {
    // default values for names
    m_firstName = "unknown";
    m_lastName = "unknown";

    for (int i = 0; i < 8; i++) m_battingStats[i] = 0; // default values for ints, hardcoding 8 ints as size
};

/* ------------------------------------------
reader(istream) - Reads names and stats into Player
------------------------------------------ */ 
void Player::reader(istream& in) {
    in >> m_firstName >> m_lastName;
    for (int i = 0;i < 8;i++) in >> m_battingStats[i]; // cycling through seemed easier

    return;
}

/* ------------------------------------------
printStats(ostream) - dumps with CSV
------------------------------------------ */ 
void Player::printStats(ostream& out) {
    out << m_firstName << ", " << m_lastName;
    for (int i = 0;i < 8;i++) out << ", " << m_battingStats[i]; // Basic comma formatting
    return;
}

/* ------------------------------------------
getBattingAvg - Calculates and Returns batting Avg
------------------------------------------ */ 
float Player::getBattingAvg() {
    float retVal = 0; // our Return Value

    if (m_battingStats[1] == 0) {// manual error control
        cout << "\nError: Player has '0' bats\n";
    }
    else {
        for (int i = 2;i <= 5;i++) { // adding 2-5
            retVal += (float)m_battingStats[i]; //casting floats for accuracy
        }
        retVal = retVal / (float)m_battingStats[1];
    }
    return(retVal);
}

/* ------------------------------------------
getOnBaseAvg() - Calculates and reports OBA
------------------------------------------ */ 
float Player::getOnBaseAvg() {
    // copy paste of getBettingAvg with number tweeks
    float retVal = 0; // our Return Value

    if (m_battingStats[0] == 0) {// manual error control
        cout << "\nError: Player has '0' on Plates\n";
    }
    else {
        for (int i = 2;i <= 7;i++) { // adding 2-8
            retVal += (float)m_battingStats[i]; //casting floats for accuracy
        }
        retVal = retVal / (float)m_battingStats[0];
    }
    return(retVal);
};

/* ------------------------------------------
getsluggingPercent() - calculates and reports OSP
------------------------------------------ */ 
float Player::getsluggingPercent() { 
    float retVal = 0.0;
    if (m_battingStats[0] == 0) {// manual error control
        cout << "\nError: Player has '0' on Plates\n";
    }
    else { // casting into float to not get a '0' because ints and division don't like eachother
        retVal = (float)(m_battingStats[2] + 2 * m_battingStats[3] + 3 * m_battingStats[4] + 4 * m_battingStats[5]) / (float)m_battingStats[1];
    }
    return retVal;
};

/* ------------------------------------------
getOnBaseSlugging() - gets OBS and reoprts
------------------------------------------ */ 

float Player::getOnBaseSlugging() {
    return(getOnBaseAvg() + getsluggingPercent()); // OnBaseSluggin = onBaseavg added to slugging percent
};


/* ------------------------------------------
get______() - returns ____
------------------------------------------ */ 
// GET Methods  -------------------------------------
string Player::getFirstName() {
    return(m_firstName);
}
string Player::getLastName() {
    return(m_lastName);
}
void Player::setName(string name){
    string delimter = " ";
    string f = name.substr(0, name.find(delimter));
    string l = name.substr(name.find(delimter)+1, name.length());

    m_firstName = f;
    m_lastName = l;
}
//Although one method with logic might be more clean, I think these method are clearer
int Player::getPlateAppearances() {
    return(m_battingStats[0]);
}
int Player::getAtBats() {
    return(m_battingStats[1]);
}
int Player::getSingles() {
    return(m_battingStats[2]);
}
int Player::getDoubles() {
    return(m_battingStats[3]);
}
int Player::getTriples() {
    return(m_battingStats[4]);
}
int Player::getHomeruns() {
    return(m_battingStats[5]);
}
int Player::getWalks() {
    return(m_battingStats[6]);
}
int Player::getHitByPitch() {
    return(m_battingStats[7]);
}
// GET Methods END-------------------------------------     


/* ------------------------------------------
printToOuputFile(ostream) - prettier dump
------------------------------------------ */ 
// Formatting methods
void Player::printToOutputFile(ostream& o) { // Tried to learn about iomanip, but this is the best I came up w/
    o << setw(8) << getLastName() << ", " << setw(8) << getFirstName() << " : ";
    o << setw(9) << setprecision(3) << getBattingAvg() << "  " << getOnBaseSlugging() << endl;
}

// New programs added for p3

// compares Players by their name

// /* ------------------------------------------
// compareTo(player) - compares player to player
//         -{-1, 0, 1} : {less, equal, greater}
// ------------------------------------------ */ 
// int Player::compareTo(Player playerItem){
//     string key1, key2;
//     int retVal;
//     key1 = getLastName() + getFirstName();
//     key2 = playerItem.getLastName() + playerItem.getFirstName(); 

//     if(key1.compare(key2) == 0){
//         retVal = 0;
//     } else if(key1.compare(key2) > 0) {
//         retVal = 1;
//     } else{
//         retVal = -1;
//     }
//     return retVal;
// }

/* ------------------------------------------
compareTo(player) - compares player to player
        -{-1, 0, 1} : {less, equal, greater}
------------------------------------------ */ 
int Player::compareTo(Player playerItem){
    float key1, key2;
    int retVal;
    key1 = getBattingAvg();
    key2 = playerItem.getBattingAvg(); 

    if(key1 == key2){
        retVal = 0;
    } else if(key2 > key1) {
        retVal = 1;
    } else{
        retVal = -1;
    }
    return retVal;
}

/* ------------------------------------------
operator_ - compareTo but with operator overload
------------------------------------------ */ 
bool Player::operator>(Player playerItem){
    return(compareTo(playerItem) == 1);
}
bool Player::operator<(Player playerItem){
    return(compareTo(playerItem) == -1);
}
bool Player::operator==(Player playerItem){
    return(compareTo(playerItem) == 0);
}

