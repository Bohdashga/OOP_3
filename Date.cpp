#include <iostream>
#include "Date.h"

Date::Date()
{
    day = 0;
    month = 0;
    year = 0;
    hours = 0;
    minutes = 0;
}

Date::Date(int day, int month, int year, int hours, int minutes)
{
    this->day = day;
    this->month = month;
    this->year = year;
    this->hours = hours;
    this->minutes = minutes;
}

Date::Date(const Date& date)
{
    day = date.day;
    month = date.month;
    year = date.year;
    hours = date.hours;
    minutes = date.minutes;
}

int Date::getDay() { return day; }
int Date::getMonth() { return month; }
int Date::getYear() { return year; }
int Date::getHours() { return hours; }
int Date::getMinutes() { return minutes; }


void Date::setDay(int day) {
    if (day > 0 && day < 32)
        this->day = day;
}

void Date::setMonth(int month) {
    if (month > 0 && month < 13)
        this->month = month;
}

void Date::setYear(int year) {
    if (year > 0)
        this->year = year;
}

void Date::setHours(int hours) {
    if (hours >= 0 && hours < 24)
        this->hours = hours;
}

void Date::setMinutes(int minutes) {
    if (minutes >= 0 && minutes <= 60)
        this->minutes = minutes;
}

string Date::toString()
{
    return to_string(day) + "/" + to_string(month) + "/" + to_string(year) +
        "  " + to_string(hours) + ":" + to_string(minutes);
}

void Date::inputFromKeyboard()
{
    cout << "Year > ";
    cin >> year;

    cout << "Month > ";
    cin >> month;

    cout << "Day > ";
    cin >> day;

    cout << "Hours > ";
    cin >> hours;

    cout << "Minutes > ";
    cin >> minutes;
}
