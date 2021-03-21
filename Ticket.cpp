#include<fstream>
#include<iostream>
#include "Ticket.h"
using namespace std;

int Ticket::ID = 0;

Ticket::Ticket()
{
    number = ++ID * 100 + rand() % 100;
    cancelTicket();
}

Ticket::Ticket(Date departDate, Date arriveDate, string departStation,
    string arriveStation, int raceNumber)
{
    number = ++ID * 100 + rand() % 100;
    sell(departDate, arriveDate, departStation, arriveStation, raceNumber);
}

Ticket::Ticket(const Ticket& obj)
{
    ID++;
    number = obj.number;
    control = obj.control;
    arriveDate = new Date(*obj.arriveDate);
    departDate = new Date(*obj.departDate);
    departStation = obj.departStation;
    arriveStation = obj.arriveStation;
    raceNumber = obj.raceNumber;
}

Ticket::~Ticket()
{
    if (arriveDate != NULL)
        delete arriveDate;
    if (departDate != NULL)
        delete departDate;

    ID--;
}

int Ticket::getCount() { return ID; }

bool Ticket::sell()
{
    return sold;
}

bool Ticket::sell(Date departDate, Date arriveDate, string departStation,
    string arriveStation, int raceNumber)
{
    if (!sold)
    {
        this->departDate = new Date(departDate);
        this->arriveDate = new Date(arriveDate);
        this->departStation = departStation;
        this->arriveStation = arriveStation;
        this->raceNumber = raceNumber;

        sold = true;
    }
    return sold;
}

bool Ticket::sell(string departStation, string arriveStation, int raceNumber)
{
    if (!sold)
    {
        this->departStation = departStation;
        this->arriveStation = arriveStation;
        this->raceNumber = raceNumber;

        sold = true;
    }
    return sold;
}

void Ticket::cancelTicket()
{
    if (arriveDate != NULL)
        delete arriveDate;
    if (departDate != NULL)
        delete departDate;

    control = false;
    arriveDate = new Date();
    departDate = new Date();
    departStation = "";
    arriveStation = "";
    raceNumber = 0;
    passanger = "";

    sold = false;
}

int Ticket::getNumber() { return number; }
bool Ticket::isControled() { return control; }
Date Ticket::getArriveDate() { return *arriveDate; }
Date Ticket::getDepartDate() { return *departDate; }
string Ticket::getDepartStation() { return departStation; }
string Ticket::getArriveStatiob() { return arriveStation; }
int Ticket::getRaceNumber() { return raceNumber; }

void Ticket::setDepartStation(string departStation) { this->departStation = departStation; }
void Ticket::setArriveStation(string arriveStation) { this->arriveStation = arriveStation; }
void Ticket::setRaceNumber(int raceNumber) { this->raceNumber = raceNumber; }

string Ticket::toString()
{
    string res = "Number: " + to_string(number) +
        "\nControlled: " + (control ? "+" : "-") +
        "\nDepart station: " + departStation +
        "\nDepart date: " + departDate->toString() +
        "\nArrive station: " + arriveStation +
        "\nArrive date: " + arriveDate->toString() +
        "\nRace number: " + to_string(raceNumber) + "\n";
    return res;
}

void Ticket::writeInFile(string fileName)
{
    ofstream file(fileName);

    if (file.is_open())
    {
        file << toString();
        file.close();
    }
}

void Ticket::inputFromKeyboard()
{
    cout << "Depart station > ";
    cin >> departStation;

    cout << "Depart date:\n";
    departDate->inputFromKeyboard();

    cout << "Arrive station > ";
    cin >> arriveStation;

    cout << "Arrive date:\n";
    arriveDate->inputFromKeyboard();

    cout << "Race number:";
    cin >> raceNumber;

    sold = true;
}
