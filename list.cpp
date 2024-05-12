#include <string>
#include <iomanip>
#include <vector>
#include <iostream>
#include <map>
#include "list.h"
#include "misc.h"

using namespace std;

List::List() : m_head(NULL) {}

List::~List() {
    Node *tmp;
    while (m_head) {
        tmp = m_head;
        m_head = m_head->m_next;
        delete tmp;
    }
}

void List::insert(WeatherData data) {
    m_head = new Node(data, m_head);
}

void List::print() {
    for (Node *ptr = m_head; ptr != nullptr; ptr = ptr->m_next) {
        cout << "Date: " << ptr->m_data.date << ", Min Temperature: " << ptr->m_data.minTemp << " Degrees Fahrenheit" << endl;
    }
}

void List::populateMonthTemps() {
    monthTemps.clear();
    for (Node* p = m_head; p != nullptr; p = p->m_next) {
        string month = p->m_data.date.substr(5, 2);
        monthTemps[month].first += p->m_data.minTemp;
        monthTemps[month].second++;
    }
}

void List::calcAllMonthAvgs() {
    misc misc;
    vector<string> months = {
        "January", "February", "March", "April", "May", "June",
        "July", "August", "September", "October", "November", "December"
    };
    if (monthTemps.empty()) {
        populateMonthTemps();
    }

    for (const auto& entry : monthTemps) {
        const string& month = entry.first;
        int totalTemp = entry.second.first;
        int count = entry.second.second;
        double avgTemp = (double)totalTemp / count;
	string final_month = months[stoi(month) -1];
	cout << " " << endl;
	misc.getInsectInfo(final_month, avgTemp);
	cout << " " << endl;
    }
}

double List::calcSpecificMonthAvg(const string& userMonth) {
    if (monthTemps.empty()) {
        populateMonthTemps();
    }

    auto it = monthTemps.find(userMonth);
    if (it != monthTemps.end() && it->second.second > 0) {
        int totalTemp = it->second.first;
        int count = it->second.second;
        double avgTemp = (double)totalTemp / count;
        return avgTemp;
    } else {
        cerr << "invalid month" << endl;
        return -1;
    }
}
