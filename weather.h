#ifndef WEATHER_H
#define WEATHER_H

#include <string>

struct WeatherData {
    std::string date;
    int minTemp;
    WeatherData(std::string d, int t) : date(d), minTemp(t) {}
};

#endif
