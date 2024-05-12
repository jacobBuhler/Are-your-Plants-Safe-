#include <iostream>
#include <vector>
#include <iomanip>
#include <fstream>
#include <string>
#include <algorithm>
#include <ctype.h>
#include "list.h"
#include "weather.h"
#include "misc.h"

using namespace std;
    
int main() {
    List weatherList;
    misc misc;
    string line, date;
    int minTemp;

    ifstream file("weather.csv");
    if (!file.is_open()) {
        cerr << "Failed to open file." << endl;
        return -1;
    }
    while (getline(file, line)) {
	if(line.length() < 70){
		getline(file, line);
	}
	else{
	    string minTempStr = line.substr(69, 2);

            if(!all_of(minTempStr.begin(), minTempStr.end(), ::isdigit)){
		getline(file, line);
            }
            else{
		minTemp = stoi(minTempStr);
	    }
	}
    	date = line.substr(42, 10);
    	WeatherData data(date, minTemp);
    	weatherList.insert(data);
    }
    file.close();
    misc.startDisplay();
    bool repeat = false;
    while(!repeat){
	string month;
	int monthName;
	bool valid = false;
	while(!valid){
	    cout << "Enter a number: ";
	    cin >> month;
	    try{
		if(month == "stop"){
		    cout << "Program Terminated" << endl;
		    return 0;
		}
		monthName = misc.toInt(month);
		if(monthName > 0 && monthName <= 14){
		    valid = true;
		}
		else{
		    throw invalid_argument("Not a Valid Number");
		}
	    } catch(const invalid_argument& e){
		cout << "Error: " << e.what() << endl;
	    }
	}	
	if(monthName == 13){
	    weatherList.calcAllMonthAvgs();
	}
	else if(monthName == 14){
	    weatherList.print();
	}
	else{
	    string name = misc.getMonthName(monthName);
	    double avgTemp = weatherList.calcSpecificMonthAvg(month);
	    misc.getInsectInfo(name, avgTemp);
	}
	cout << endl;
	cout << "Type 'stop' to terminate program or type a number to continue" << endl;
    }
	return 0;
}
