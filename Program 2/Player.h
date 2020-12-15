#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

class Player {
private:
    int m_battingStats[8];// plateappearances atbats singles doubles triples homeruns walks hitbypitch
    string m_firstName, m_lastName; //names
public:
    // bigger functions are defined later
    Player();
    void reader(istream& in);
    void printStats(ostream& out);
    float getBattingAvg();
    float getOnBaseAvg();

    // Newly Added Methods for Program 2
    float getsluggingPercent();
    float getOnBaseSlugging();

    // Simple 1 line 'gets' are defined here as stated in instructions
    string getFirstName();
    string getLastName();
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
    void printToOutputFile(ostream& o);
};