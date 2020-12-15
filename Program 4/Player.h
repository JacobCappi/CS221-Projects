#include <iostream>
#include <string>
#include <iomanip>

// EDIT: header guards because PlayerList issues?
// Also removed std from global namespace
#ifndef PLAYER_H
#define PLAYER_H

/* ------------------------------------------
Player{}, class storing data on baseball Players
    battingStats in array of size 8.
    m_firstname, m_lastname

    methods are mainly get_____()
    along with reader(), printStats()
    along with overloaded operators
------------------------------------------ */ 
class Player {
private:
    int m_battingStats[8];// plateappearances atbats singles doubles triples homeruns walks hitbypitch
    std::string m_firstName, m_lastName; //names
public:
    // bigger functions are defined later
    Player();
    void reader(std::istream& in);
    void printStats(std::ostream& out);
    float getBattingAvg();
    float getOnBaseAvg();

    // Newly Added Methods for Program 2
    float getsluggingPercent();
    float getOnBaseSlugging();

    //Newly Added Method for P3
    void setName(std::string name);

    // Simple 1 line 'gets' are defined here as stated in instructions
    std::string getFirstName();
    std::string getLastName();
    
    //Although one method with logic might be more clean, I think these method are clearer
    int getPlateAppearances();
    int getAtBats();
    int getSingles();
    int getDoubles();
    int getTriples();
    int getHomeruns();
    int getWalks();
    int getHitByPitch();

    //Formatting method for output file
    void printToOutputFile(std::ostream& o);

    // New Programs
    int compareTo(Player playerItem); // Compares two different player objects.
    bool operator>(Player playerItem);
    bool operator<(Player playerItem);
    bool operator==(Player playerItem);
};

#endif