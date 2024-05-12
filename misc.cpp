#include "misc.h"
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

int misc::toInt(const string& month){
    for(char i : month){
        if(!isdigit(i)){
	    throw invalid_argument("Not a Valid Number");
	}
    }
    return stoi(month);
}

void misc::startDisplay(){
    cout << "----------------------------------" << endl;
    cout << "**Plant Safety Analysis by Month**" << endl;
    cout << "----------------------------------" << endl;
    cout << "01: January" << endl;
    cout << "02: February" << endl;
    cout << "03: March" << endl;
    cout << "04: April" << endl;
    cout << "05: May" << endl;
    cout << "06: June" << endl;
    cout << "07: July" << endl;
    cout << "08: August" << endl;
    cout << "09: September" << endl;
    cout << "10: October" << endl;
    cout << "11: November" << endl;
    cout << "12: December" << endl;
    cout << "13: All Months" << endl;
    cout << "14: Print All Weather Data" << endl;
    cout << "----------------------------------" << endl;
}
string misc::getMonthName(int monthNumber){
    vector<string> months = {
        "January", "February", "March", "April", "May", "June",
        "July", "August", "September", "October", "November", "December"
    };
    return months[monthNumber -1];
}
void misc::getInsectInfo(string name, double avgTemp){
    cout << endl;
    cout << "-----------------------------------------" << endl;
    cout << "**Plant Safety Analysis for " << name << "**" << endl;
    cout << "-----------------------------------------" << endl;
    cout << endl;
    cout << "Average Minimum Temperature: " << setprecision(3) << avgTemp << " Fahrenheit." << endl;
    if(avgTemp >= 48 && avgTemp < 50){
	cout << "Insects to worry about: ";
        aphids();
    }
    if(avgTemp >= 50 && avgTemp < 52){
	cout << "Insects to worry about: ";
        westernFlowerThrips();
	spiderMites();
	aphids();
    }
    if(avgTemp >= 52){
	cout << "Insects to worry about: " << endl;
        aphids();
	westernFlowerThrips();
	spiderMites();
	leafHoppers();
    }
    else{
        cout << " " << endl;
	cout << "Insects to worry about: None" << endl;
    }
    
}

void misc::westernFlowerThrips(){
    cout << " " << endl;
    cout << "----------------------" << endl;
    cout << "Western Flower Thrips" << endl;
    cout << "These insects are generally inactive during cold weather and start to become active when above 50 degrees" << endl;
    cout << "---------------------------------------------------------------------------------------------------------" << endl;
}

void misc::spiderMites(){
    cout << " " << endl;
    cout << "------------" << endl;
    cout << "Spider Mites" << endl;
    cout << "They become active when min temp is above 50 degrees" << endl;
    cout << "----------------------------------------------------" << endl;
}

void misc::aphids(){
    cout << " " << endl;
    cout << "------" << endl;
    cout << "Aphids" << endl;
    cout << "They become active when the min temp is above 48 degrees" << endl;
    cout << "--------------------------------------------------------" << endl;
}

void misc::leafHoppers(){
    cout << " " << endl;
    cout << "-----------" << endl;
    cout << "Leafhoppers" << endl;
    cout << "They become active when min temp rises above 52 degrees" << endl;
    cout << "-------------------------------------------------------" << endl;
}
