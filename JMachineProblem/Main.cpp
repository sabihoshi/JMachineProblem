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
start:
    const int choice = Menu();
    if (choice == 1)
    {
        system("clear||cls");
        cout << "\n\n\n\n\n";
        cout << string(30, ' ') << "=============================================================================\n";
        cout << string(50, ' ') << "INSERT A NEW MOVIE\n";
        cout << string(30, ' ') << "=============================================================================\n\n";
        store.AddMovie();
    }
    else if (choice == 2)
    {
        cout << "Rent A Movie" << endl;

        int movieCode;
        cout << "Enter the movie code: ";
        cin >> movieCode;

        auto movie = store.GetVideo(movieCode);
        if (!movie)
        {
            cout << "Movie not found" << endl;
            goto start;
        }

        int customerCode;
        cout << "Enter the customer code: ";
        cin >> customerCode;

        auto customer = store.GetCustomer(customerCode);
        if (!customer)
        {
            cout << "Customer not found" << endl;
            goto start;
        }

        store.RentMovie(*customer, *movie);
    }
    else if (choice == 3)
    {
        cout << "Return A Movie" << endl;

        int movieCode;
        cout << "Enter the movie code: ";
        cin >> movieCode;

        auto movie = store.GetVideo(movieCode);
        if (!movie)
        {
            cout << "Movie not found" << endl;
            goto start;
        }

        int customerCode;
        cout << "Enter the customer code: ";
        cin >> customerCode;

        auto customer = store.GetCustomer(customerCode);
        if (!customer)
        {
            cout << "Customer not found" << endl;
            goto start;
        }

        store.ReturnMovie(*customer, *movie);
    }
    else if (choice == 4)
    {
        cout << "Show Movie Details" << endl;

        int movieCode;
        cout << "Enter the movie code: ";
        cin >> movieCode;

        auto movie = store.GetVideo(movieCode);
        if (!movie)
        {
            cout << "Movie not found" << endl;
            goto start;
        }

        MovieStore::ShowMovieDetails(*movie);
    }
    else if (choice == 5)
    {
        system("clear||cls");
        store.DisplayMovies();
        cout << string(50, ' ') << "\nPress enter key to continue... ";
        cin.ignore();
        cin.get();
    }
    else if (choice == 6)
    {
        cout << "Check Movie Availability" << endl;

        int movieCode;
        cout << "Enter the movie code: ";
        cin >> movieCode;

        auto movie = store.GetVideo(movieCode);
        if (!movie)
        {
            cout << "Movie not found" << endl;
            goto start;
        }

        if (movie->Copies > 0)
        {
            cout << "Movie is available" << endl;
        }
        else
        {
            cout << "Movie is not available" << endl;
        }

    }
    else if (choice == 7)
    {
        system("clear||cls");
        cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n";
        cout << string(30, ' ') << "==========================================================================================\n\n";
        cout << string(50, ' ') << "CUSTOMER MAINTENANCE" << "\n\n";
        cout << string(30, ' ') << "==========================================================================================\n\n\n";
        cout << string(50, ' ') << "[1] Add New Customer\n\n";
        cout << string(50, ' ') << "[2] Customer Details\n\n";
        cout << string(50, ' ') << "[3] List of Movies Rented\n\n";
        cout << string(30, ' ') << "==========================================================================================\n";
        int ch1;
        cout << string(50, ' ') << "Please choose an option... ";
        cin >> ch1;
        if (ch1 == 1)
        {
            system("clear||cls");
            cout << "\n\n\n\n\n";
            cout << string(30, ' ') << "=============================================================================\n";
            cout << string(50, ' ') << "INSERT A NEW CUSTOMER\n";
            cout << string(30, ' ') << "=============================================================================\n\n";
            store.AddCustomer();
            cout << string(50, ' ') << "Press enter key to continue... ";
            cin.ignore();
            cin.get();
        }
        else if (ch1 == 2)
        {
            cout << "Show Customer Details" << endl;

            int customerCode;
            cout << "Enter the customer code: ";
            cin >> customerCode;

            auto customer = store.GetCustomer(customerCode);
            if (!customer)
            {
                cout << "Customer not found" << endl;
                goto start;
            }

            store.ShowCustomerDetails(*customer);
        }
        else if (ch1 == 3)
        {
            cout << "List All Movies Rented By The Customer" << endl;

            int customerCode;
            cout << "Enter the customer code: ";
            cin >> customerCode;

            auto customer = store.GetCustomer(customerCode);
            if (!customer)
            {
                cout << "Customer not found" << endl;
                goto start;
            }

            // Get all movies by the customer
            auto movies = store.GetMoviesByCustomer(*customer);
            store.DisplayMovies(movies);
        }
        else
        {
            cout << "Try Again.";
        }
    }
    else if (choice == 8)
    {
        store.SaveMovieFile();
        store.SaveCustomerFile();
        store.SaveRentFile();
        cout << "Thank You! Please Come Again" << endl;
        exit(0);
    }
    else
    {
        cout << "Try Again.";
        system("pause");
    }

    std::cout << "Press enter to continue...";
    std::string pause;
    std::getline(std::cin, pause);

    goto start;
}

int Menu()
{
    int choice;
    system("clear||cls");
    cout << "\n\n\n\n\n\n\n\n";
    cout << string(30, ' ') << "==========================================================================================\n\n";
    cout << string(50, ' ') << "Hey there, movie geek! What can I do for you?" << "\n\n";
    cout << string(30, ' ') << "==========================================================================================\n\n\n";
    cout << string(50, ' ') << "[1] Insert a New Movie\n\n";
    cout << string(50, ' ') << "[2] Rent a Movie\n\n";
    cout << string(50, ' ') << "[3] Return a Movie\n\n";
    cout << string(50, ' ') << "[4] Show Movie Details\n\n";
    cout << string(50, ' ') << "[5] Display All Movie\n\n";
    cout << string(50, ' ') << "[6] Check Movie Availability\n\n";
    cout << string(50, ' ') << "[7] Customer's Maintenance\n\n";
    cout << string(50, ' ') << "[8] Exit Program\n\n";
    cout << string(30, ' ') << "==========================================================================================\n\n";
    cout << string(50, ' ') << "Please choose an option... ";
    cin >> choice;

    return choice;
}
