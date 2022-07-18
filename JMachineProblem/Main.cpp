/*  STAR PLATINUM GROUP MEMBERS
    Jairell Louis J. Ignacio [Lead Programmer]
    Shahani Fe D. Vicio      [Programmer 1]
    Jasmine L. Camasura      [Programmer 2] */

#include <iomanip>
#include <iostream>
#include <string>

#include "Data.h"
using namespace std;

int Menu();

int main()
{
    MovieStore store;
    store.OpenMovieFile();
    store.OpenCustomerFile();
    store.OpenRentFile();

Start:
    system("cls||clear");
    const int choice = Menu();
    system("cls||clear");

    if (choice == 1)
    {
        store.AddMovie();
    }
    else if (choice == 2)
    {
        store.RentMovie();
    }
    else if (choice == 3)
    {
        store.ReturnMovie();
    }
    else if (choice == 4)
    {
        store.ShowMovieDetails();
    }
    else if (choice == 5)
    {
        store.DisplayMovies();
    }
    else if (choice == 6)
    {
        store.CheckVideoAvailability();
    }
    else if (choice == 7)
    {
        store.CustomerMaintenance();
    }
    else if (choice == 8)
    {
        store.SaveMovieFile();
        store.SaveCustomerFile();
        store.SaveRentFile();
        cout << "Thank You! Please Come Again" << endl;

        return 0;
    }
    else
    {
        if (!cin) cin.clear();
        cout << "Try Again.";
    }

    std::cout << "Press enter to continue...";
    cin.ignore(10000, '\n');
    std::string pause;
    std::getline(std::cin, pause);

    goto Start;
}

int Menu()
{
    int choice;
    cout << string(10, ' ') << "==========================================================================================\n";
    cout << string(30, ' ') << "Hey there, movie geek! What can I do for you?" << "\n";
    cout << string(10, ' ') << "==========================================================================================\n";
    cout << string(40, ' ') << "[1] Insert a New Movie\n";
    cout << string(40, ' ') << "[2] Rent a Movie\n";
    cout << string(40, ' ') << "[3] Return a Movie\n";
    cout << string(40, ' ') << "[4] Show Movie Details\n";
    cout << string(40, ' ') << "[5] Display All Movie\n";
    cout << string(40, ' ') << "[6] Check Movie Availability\n";
    cout << string(40, ' ') << "[7] Customer's Maintenance\n";
    cout << string(40, ' ') << "[8] Exit Program\n";
    cout << string(10, ' ') << "==========================================================================================\n\n";
    cout << string(10, ' ') << "Please choose an option... ";
    cin >> choice;

    return choice;
}
