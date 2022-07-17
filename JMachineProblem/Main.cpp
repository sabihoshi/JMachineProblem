/*  STAR PLATINUM GROUP MEMBERS
    Jairell Louis J. Ignacio [Lead Programmer]
    Shahani Fe D. Vicio      [Programmer 1]
    Jasmine L. Camasura      [Programmer 2] */

#include "Data.h"
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;
int menu();
int main()
{
    movieList movie;
    VideoAdt mov;
    CustomerAdt cust;
    int customerDetails;
    movie.OpenMovieFile();
    movie.OpenCustomerFile();
start: int choice;
    choice = menu();
    cout << "Enter your choice: " << endl;
    if (choice == 1)
    {
        system("clear||cls");
        cout << "\n\n\n\n\n";
        cout << setw(112) << "=============================================================================\n";
        cout << setw(81) << "INSERT A NEW MOVIE\n";
        cout << setw(113) << "=============================================================================\n\n";
        movie.addMovie(mov);
        cout << setw(68) << "Press enter key to continue... ";
        cin.ignore();
        cin.get();
    }
    else if (choice == 2)
    {
        cout << "Rent A Movie" << endl;
    }
    else if (choice == 3)
    {
        cout << "Return A Movie" << endl;
    }
    else if (choice == 4)
    {
        void OpenMovieFile();
        cout << "Show Movie Details" << endl;
        cout << setw(68) << "Press enter key to continue... ";
        system("pause");
    }
    else if (choice == 5)
    {
        system("clear||cls");
        movie.displayMovies();
        cout << setw(68) << "\nPress enter key to continue... ";
        cin.ignore();
        cin.get();
    }
    else if (choice == 6)
    {
        cout << "Check Movie Availability" << endl;
        cout << setw(68) << "Press enter key to continue... ";
        system("pause");
    }
    else if (choice == 7)
    {
        system("clear||cls");
        cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n";
        cout << setw(124) << "==========================================================================================\n\n";
        cout << setw(98) << "CUSTOMER MAINTENANCE" << "\n\n";
        cout << setw(125) << "==========================================================================================\n\n\n";
        cout << setw(80) << "[1] Add New Customer\n\n";
        cout << setw(80) << "[2] Customer Details\n\n";
        cout << setw(85) << "[3] List of Movies Rented\n\n";
        cout << setw(123) << "==========================================================================================\n";
        int ch1;
        cout << setw(62) << "Please choose an option... ";
        cin >> ch1;
        if (ch1 == 1)
        {
            system("clear||cls");
            cout << "\n\n\n\n\n";
            cout << setw(112) << "=============================================================================\n";
            cout << setw(81) << "INSERT A NEW CUSTOMER\n";
            cout << setw(113) << "=============================================================================\n\n";
            movie.addCustomer(cust);
            cout << setw(68) << "Press enter key to continue... ";
            cin.ignore();
            cin.get();
        }
        else if (ch1 == 2)
        {
            cout << "Show Customer Details" << endl;
        }
        else if (ch1 == 3)
        {
            cout << "List All Movies Rented By The Customer" << endl;
            cout << setw(68) << "Press enter key to continue... ";
            system("pause");
        }
        else
        {
            cout << "Try Again.";
        }
        system("pause");
    }
    else if (choice == 8)
    {
        movie.SaveMovieFile();
        movie.SaveCustomerFile();
        cout << "Thank You! Please Come Again" << endl;
        exit(0);
    }
    else
    {
        cout << "Try Again.";
        system("pause");
    }
    goto start;
}
int menu()
{
    int choice;
    system("clear||cls");
    cout << "\n\n\n\n\n\n\n\n";
    cout << setw(124) << "==========================================================================================\n\n";
    cout << setw(98) << "Hey there, movie geek! What can I do for you?" << "\n\n";
    cout << setw(125) << "==========================================================================================\n\n\n";
    cout << setw(85) << "[1] Insert a New Movie\n\n";
    cout << setw(79) << "[2] Rent a Movie\n\n";
    cout << setw(81) << "[3] Return a Movie\n\n";
    cout << setw(85) << "[4] Show Movie Details\n\n";
    cout << setw(84) << "[5] Display All Movie\n\n";
    cout << setw(91) << "[6] Check Movie Availability\n\n";
    cout << setw(89) << "[7] Customer's Maintenance\n\n";
    cout << setw(79) << "[8] Exit Program\n\n";
    cout << setw(123) << "==========================================================================================\n";
    cout << setw(62) << "Please choose an option... ";
    cin >> choice;
    return (choice);
}