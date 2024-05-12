#ifndef MISC_H
#define MISC_H

#include <string>
using namespace std;

class misc{
public:
    string getMonthName(int monthNumber);
    int toInt(const string& month);
    void startDisplay();
    void getInsectInfo(string name, double avgTemp);
    void westernFlowerThrips();
    void aphids();
    void leafHoppers();
    void spiderMites();
};
#endif
