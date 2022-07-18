#include <iomanip>
#include <iostream>
#include <string>
#include <fstream>

#include "Data.h"
using namespace std;
using namespace nlohmann;

void MovieStore::DisplayMovies()
{
    DisplayMovies(videoList);
}

//Display All Movies - Programmer 1
void MovieStore::DisplayMovies(list<VideoAdt>& movies)
{
    cout << left;
    cout << "======================================================================================================================\n";
    cout << string(50, ' ') << "DISPLAY MOVIES\n";
    cout << "======================================================================================================================\n\n";
    cout << setw(5) << "ID" << setw(10) << "TITLE" << setw(30) << "GENRE" << setw(30) << "PRODUCTION" << "NO. OF COPIES\n";
    cout << "======================================================================================================================\n";
    for (auto& video : movies)
    {
        cout << setw(5) << video.Id;
        cout << setw(10) << video.Title;
        cout << setw(30) << video.Genre;
        cout << setw(30) << video.Production;
        cout << video.Copies << endl;
    }
}

//Add Movie - Programmer 1
void MovieStore::AddMovie()
{
    cout << string(10, ' ') << "=============================================================================\n";
    cout << string(50, ' ') << "INSERT A NEW MOVIE\n";
    cout << string(10, ' ') << "=============================================================================\n\n";

    int count = videoList.size() + 1;

    cout << string(30, ' ') << "Enter Movie Details" << endl;
    cout << string(30, ' ') << "Code: " << count << "\n";

    cout << string(30, ' ') << "Title: ";
    string title;
    cin.ignore();
    getline(cin, title);

    cout << string(30, ' ') << "Genre: ";
    string genre;
    getline(cin, genre);

    cout << string(30, ' ') << "Producer: ";
    string producer;
    getline(cin, producer);

    cout << string(30, ' ') << "Image: ";
    string image;
    getline(cin, image);

    int copies;
    cout << string(30, ' ') << "Copies: ";
    cin >> copies;

    videoList.push_back({count, copies, title, genre, producer, image});

    cout << string(10, ' ') << "=============================================================================\n";
    cout << string(50, ' ') << "Movie has been inserted successfully!\n";
    cout << string(10, ' ') << "=============================================================================\n";
}

void MovieStore::ReturnMovie()
{
    cout << string(10, ' ') << "=============================================================================\n";
    cout << string(50, ' ') << "RETURN A MOVIE\n";
    cout << string(10, ' ') << "=============================================================================\n";

    int movieCode;
    cout << string(30, ' ') << "Enter the movie code: ";
    cin >> movieCode;

    auto movie = GetVideo(movieCode);
    if (!movie)
    {
        cout << string(30, ' ') << "Movie not found" << endl;
        cout << string(10, ' ') << "=============================================================================\n";
        return;
    }

    int customerCode;
    cout << string(30, ' ') << "Enter the customer code: ";
    cin >> customerCode;

    auto customer = GetCustomer(customerCode);
    if (!customer)
    {
        cout << string(30, ' ') << "Customer not found" << endl;
        cout << string(10, ' ') << "=============================================================================\n";
        return;
    }

    ReturnMovie(*customer, *movie);
}

void MovieStore::ShowMovieDetails()
{
    cout << string(10, ' ') << "=============================================================================\n";
    cout << string(50, ' ') << "SHOW MOVIE DETAILS\n";
    cout << string(10, ' ') << "=============================================================================\n";

    int movieCode;
    cout << string(30, ' ') << "Enter the movie code: ";
    cin >> movieCode;

    auto movie = GetVideo(movieCode);
    if (!movie)
    {
        cout << "Movie not found" << endl;
        cout << string(10, ' ') << "=============================================================================\n";
        return;
    }

    ShowMovieDetails(*movie);
}

void MovieStore::CheckVideoAvailability()
{
    cout << string(10, ' ') << "=============================================================================\n";
    cout << string(50, ' ') << "CHECK MOVIE AVAILABILITY\n";
    cout << string(10, ' ') << "=============================================================================\n";

    int movieCode;
    cout << "Enter the movie code: ";
    cin >> movieCode;

    auto movie = GetVideo(movieCode);
    if (!movie)
    {
        cout << string(30, ' ') << "Movie not found" << endl;
        cout << string(10, ' ') << "=============================================================================\n";
    }
    else if (movie->Copies > 0)
    {
        cout << string(30, ' ') << "Movie is available" << endl;
        cout << string(10, ' ') << "=============================================================================\n";
    }
    else
    {
        cout << string(30, ' ') << "Movie is not available" << endl;
        cout << string(10, ' ') << "=============================================================================\n";
    }
}

void MovieStore::CustomerMaintenance()
{
    cout << string(10, ' ') << "==========================================================================================\n";
    cout << string(30, ' ') << "CUSTOMER MAINTENANCE\n";
    cout << string(10, ' ') << "==========================================================================================\n";
    cout << string(30, ' ') << "[1] Add New Customer\n";
    cout << string(30, ' ') << "[2] Customer Details\n";
    cout << string(30, ' ') << "[3] List of Movies Rented\n";
    cout << string(10, ' ') << "==========================================================================================\n\n";

    int choice;
    cout << string(30, ' ') << "Please choose an option... ";
    cin >> choice;

    system("clear||cls");

    if (choice == 1)
    {
        cout << string(10, ' ') << "=============================================================================\n";
        cout << string(30, ' ') << "INSERT A NEW CUSTOMER\n";
        cout << string(10, ' ') << "=============================================================================\n";

        int count = customerQueue.size() + 1;

        cout << '\n' << string(30, ' ') << "Enter Customer Details" << endl;
        cout << string(30, ' ') << "Code: " << count;

        string name;
        cin.ignore();
        cout << string(30, ' ') << "Name: ";
        getline(cin, name);

        string address;
        cout << string(30, ' ') << "Address: ";
        getline(cin, address);

        customerQueue.push_back({count, name, address});

        cout << "\n\n" << string(30, ' ') << "New Customer Added Successfully!\n" << endl;
        cout << string(30, ' ') << "=============================================================================\n";
    }
    else if (choice == 2)
    {
        cout << string(10, ' ') << "=============================================================================\n";
        cout << string(30, ' ') << "SHOW CUSTOMER DETAILS\n";
        cout << string(10, ' ') << "=============================================================================\n";

        int customerCode;
        cout << "Enter the customer code: ";
        cin >> customerCode;

        auto customer = GetCustomer(customerCode);
        if (!customer)
        {
            cout << "Customer not found" << endl;
            return;
        }

        ShowCustomerDetails(*customer);
    }
    else if (choice == 3)
    {
        cout << string(10, ' ') << "=============================================================================\n";
        cout << string(30, ' ') << "LIST ALL VIDEOS RENTED BY A CUSTOMER\n";
        cout << string(10, ' ') << "=============================================================================\n";

        int customerCode;
        cout << "Enter the customer code: ";
        cin >> customerCode;

        auto customer = GetCustomer(customerCode);
        if (!customer)
        {
            cout << "Customer not found" << endl;
            return;
        }

        auto movies = GetMoviesByCustomer(*customer);

        ShowCustomerDetails(*customer);
        DisplayMovies(movies);
    }
    else
    {
        cout << "Try Again.";
    }
}

void MovieStore::RentMovie()
{
    cout << string(10, ' ') << "=============================================================================\n";
    cout << string(50, ' ') << "RENT A MOVIE\n";
    cout << string(10, ' ') << "=============================================================================\n";

    int movieCode;
    cout << "Enter the movie code: ";
    cin >> movieCode;

    auto movie = GetVideo(movieCode);
    if (!movie)
    {
        cout << string(30, ' ') << "Movie not found" << endl;
        cout << string(10, ' ') << "=============================================================================\n";
        return;
    }

    int customerCode;
    cout << "Enter the customer code: ";
    cin >> customerCode;

    auto customer = GetCustomer(customerCode);
    if (!customer)
    {
        cout << string(30, ' ') << "Customer not found" << endl;
        cout << string(10, ' ') << "=============================================================================\n";
        return;
    }

    RentMovie(*customer, *movie);
}

bool MovieStore::RentMovie(CustomerAdt& customer, VideoAdt& video)
{
    if (video.Copies > 0)
    {
        video.Copies--;
        rentList.push_back({customer.Id, video.Id});
        cout << string(30, ' ') << "Movie has been rented successfully!\n";
        cout << string(10, ' ') << "=============================================================================\n";

        return true;
    }

    cout << string(30, ' ') << "Movie is out of stock!\n";
    cout << string(10, ' ') << "=============================================================================\n";

    return false;
}

bool MovieStore::ReturnMovie(CustomerAdt& customer, VideoAdt& video)
{
    for (auto& rent : rentList)
    {
        if (rent.CustomerId == customer.Id && rent.VideoId == video.Id)
        {
            video.Copies++;
            rentList.erase(find(rentList.begin(), rentList.end(), rent));
            cout << string(30, ' ') << "Movie has been returned successfully!\n";
            cout << string(10, ' ') << "=============================================================================\n";
            return true;
        }
    }

    cout << string(30, ' ') << "Movie is not rented by this customer!\n";
    cout << string(10, ' ') << "=============================================================================\n";
    return false;
}

void MovieStore::ShowMovieDetails(VideoAdt& video)
{
    cout << left;
    cout << "======================================================================================================================\n";
    cout << string(50, ' ') << "DISPLAY MOVIE\n";
    cout << "======================================================================================================================\n";
    cout << setw(5) << "ID" << setw(10) << "TITLE" << setw(30) << "GENRE" << setw(30) << "PRODUCTION" << "NO. OF COPIES\n";
    cout << "======================================================================================================================\n";

    cout << setw(5) << video.Id;
    cout << setw(10) << video.Title;
    cout << setw(30) << video.Genre;
    cout << setw(30) << video.Production;
    cout << video.Copies << endl << endl;
}

void MovieStore::ShowCustomerDetails(CustomerAdt& video)
{
    cout << left;
    cout << "======================================================================================================================\n";
    cout << string(50, ' ') << "DISPLAY CUSTOMER\n";
    cout << "======================================================================================================================\n";
    cout << setw(5) << "ID" << setw(10) << "NAME" << "ADDRESS" << endl;
    cout << "======================================================================================================================\n";

    cout << setw(5) << video.Id;
    cout << setw(10) << video.Name;
    cout << video.Address << endl << endl;
}

list<VideoAdt> MovieStore::GetMoviesByCustomer(CustomerAdt& customer)
{
    list<VideoAdt> movies;
    for (auto& rent : rentList)
    {
        if (rent.CustomerId == customer.Id)
        {
            auto video = GetVideo(rent.VideoId);
            movies.push_back(*video);
        }
    }
    return movies;
}

CustomerAdt* MovieStore::GetCustomer(int id)
{
    for (auto& customer : customerQueue)
    {
        if (customer.Id == id)
        {
            return &customer;
        }
    }
    return nullptr;
}

VideoAdt* MovieStore::GetVideo(int id)
{
    for (auto& video : videoList)
    {
        if (video.Id == id)
        {
            return &video;
        }
    }
    return nullptr;
}

//Save Movie File - Programmer 1
void MovieStore::SaveMovieFile()
{
    ofstream openMov("Movies.json");

    json j = videoList;
    openMov << j.dump(4);
}

//Save Customer File - Programmer 1
void MovieStore::SaveCustomerFile()
{
    ofstream openCust("Customers.json");

    json j = customerQueue;
    openCust << j.dump(4);
}

void MovieStore::SaveRentFile()
{
    ofstream openRent("Rent.json");

    json j = rentList;
    openRent << j.dump(4);
}

//Opening Movie File - Programmer 1
void MovieStore::OpenMovieFile()
{
    ifstream openMov("Movies.json");

    json j;
    openMov >> j;

    videoList = j.get<list<VideoAdt>>();
}

void MovieStore::OpenRentFile()
{
    ifstream openRent("Rent.json");

    json j;
    openRent >> j;

    rentList = j.get<list<RentAdt>>();
}

//Open Customer File - Programmer 1
void MovieStore::OpenCustomerFile()
{
    ifstream openCust("Customers.json");

    json j;
    openCust >> j;

    customerQueue = j.get<deque<CustomerAdt>>();
}