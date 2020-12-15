
#include "Player.h"

using namespace std;

// default init if no parameters are passed
Player::Player() {
    // default values for names
    m_firstName = "unknown";
    m_lastName = "unknown";

    for (int i = 0; i < 8; i++) m_battingStats[i] = 0; // default values for ints, hardcoding 8 ints as size
};

void Player::reader(istream& in) {
    in >> m_firstName >> m_lastName;
    for (int i = 0;i < 8;i++) in >> m_battingStats[i]; // cycling through seemed easier

    return;
}

void Player::printStats(ostream& out) {
    out << m_firstName << ", " << m_lastName;
    for (int i = 0;i < 8;i++) out << ", " << m_battingStats[i]; // Basic comma formatting
    return;
}

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

float Player::getOnBaseSlugging() {
    return(getOnBaseAvg() + getsluggingPercent()); // OnBaseSluggin = onBaseavg added to slugging percent
};


// GET Methods  -------------------------------------
string Player::getFirstName() {
    return(m_firstName);
}
string Player::getLastName() {
    return(m_lastName);
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

// Formatting methods
void Player::printToOutputFile(ostream& o) { // Tried to learn about iomanip, but this is the best I came up w/
    o << setw(8) << getLastName() << ", " << setw(8) << getFirstName() << " : ";
    o << setw(9) << setprecision(3) << getBattingAvg() << "  " << getOnBaseSlugging() << endl;
}
