#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <ctime>

#include "Date.h"
#include "Ticket.h"

using namespace std;

int main()
{
    srand(time(nullptr));

    Ticket ticket;

    cout << "Creating object with default constructor:" << endl;
    string ticketStr = ticket.toString();
    cout << ticketStr << endl;

    Ticket* ticket2 = new Ticket(Date(5, 4, 2020, 14, 25),
        Date(6, 4, 2020, 15, 45),
        "Kiev", "Kharkiv", 5);


    cout << "Creating object with constructor with parameters:" << endl;
    ticketStr = ticket2->toString();
    cout << ticketStr << endl;

    cout << "Sell method with no parameters: " << ticket2->sell() << endl << endl;

    cout << "Working CANCEL method:" << endl;
    ticket2->cancelTicket();
    ticketStr = ticket2->toString();
    cout << ticketStr << endl;


    cout << "Overload Sell method with parameters: " << endl << endl;
    ticket2->sell(Date(5, 2, 2021, 15, 24),
        Date(6, 2, 2021, 13, 27),
        "Dnepr", "Lviv", 23);
    ticketStr = ticket2->toString();
    cout << ticketStr << endl;

    delete ticket2;

    Ticket* ticket3 = new Ticket();

    cout << "Inputing from keyboard:\n\n";
    ticket3->inputFromKeyboard();

    cout << "Result:\n\n";
    ticketStr = ticket3->toString();
    cout << ticketStr << endl;

    string fileName;

    cout << "\nInput file name > ";
    cin >> fileName;

    ticket3->writeInFile(fileName);


    return 0;
}
