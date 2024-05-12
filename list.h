#ifndef LIST_H
#define LIST_H

#include "weather.h"

#include <iostream>
#include <map>
#include <string>

class List {
public:
    List();
    ~List();
    void insert(WeatherData data);
    void print();
    void calcAllMonthAvgs();
    double calcSpecificMonthAvg(const std::string &userMonth);
    void populateMonthTemps();
private:
    class Node {
    public:
        Node(WeatherData data, Node *next) : m_data(data), m_next(next) {}
        WeatherData m_data;
        Node *m_next;
    };
    Node *m_head;
    std::map<std::string, std::pair<int, int>> monthTemps;
};

#endif
