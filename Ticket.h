#pragma once

#include <string>

#include "Date.h"

using namespace std;

class Ticket
{
private:
    int static ID;
    int number;
protected:
    bool control;
private:
    Date* arriveDate;
    Date* departDate;
    string departStation;
    string arriveStation;
    int raceNumber;

    bool sold;
public:
    string passanger;

    Ticket();

    Ticket(Date departDate, Date arriveDate, string departStation,
        string arriveStation, int raceNumber);

    Ticket(const Ticket& obj);

    ~Ticket();

    int getCount();

    bool sell();

    bool sell(Date departDate, Date arriveDate, string departStation,
        string arriveStation, int raceNumber);

    bool sell(string departStation, string arriveStation, int raceNumber);

    void cancelTicket();

    int getNumber();
    bool isControled();
    Date getArriveDate();
    Date getDepartDate();
    string getDepartStation();
    string getArriveStatiob();
    int getRaceNumber();

    void setDepartStation(string departStation);
    void setArriveStation(string arriveStation);
    void setRaceNumber(int raceNumber);

    string toString();

    void writeInFile(string fileName);

    void inputFromKeyboard();
};

