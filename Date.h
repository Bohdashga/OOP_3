#pragma once


#include <string>

using namespace std;

class Date
{
private:
    int day, month, year;
    int hours, minutes;
public:
    Date();

    Date(int day, int month, int year, int hours, int minutes);

    Date(const Date& date);

    int getDay();
    int getMonth();
    int getYear();
    int getHours();
    int getMinutes();

    void setDay(int day);

    void setMonth(int month);

    void setYear(int year);

    void setHours(int hours);

    void setMinutes(int minutes);

    string toString();

    void inputFromKeyboard();
};

