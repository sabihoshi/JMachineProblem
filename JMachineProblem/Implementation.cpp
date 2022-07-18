#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>

#include "Data.h"
using namespace std;
using namespace nlohmann;

void MovieStore::DisplayMovies()
{
    DisplayMovies(videoList);
}

//Display All Movies - Programmer 1
void MovieStore::DisplayMovies(vector<VideoAdt>& movies)
{
    cout << "\n\n\n\n\n\n\n\n\n\n\n";
    cout << left;
    cout << "======================================================================================================================\n";
    cout << string(40, ' ') << "DISPLAY MOVIES\n";
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
    cout << "\n\n\n\n\n\n\n\n\n\n\n";
    cout << string(35, ' ') << "=============================================================================\n";
    cout << string(64, ' ') << "INSERT A NEW MOVIE\n";
    cout << string(35, ' ') << "=============================================================================\n\n";

    int count = videoList.size() + 1;

    cout << string(48, ' ') << "Movie ID       : " << count << "\n";

    cout << '\n' << string(48, ' ') << "Movie Title    : ";
    string title;
    cin.ignore();
    getline(cin, title);

    cout << '\n' << string(48, ' ') << "Movie Genre    : ";
    string genre;
    getline(cin, genre);

    cout << '\n' << string(48, ' ') << "Production     : ";
    string producer;
    getline(cin, producer);

    cout << '\n' << string(48, ' ') << "Image Filename : ";
    string image;
    getline(cin, image);

    int copies;
    cout << '\n' << string(48, ' ') << "Copies Count   : ";
    cin >> copies;

    videoList.push_back({count, copies, title, genre, producer, image});
    sort(videoList.begin(), videoList.end());

    cout << endl;
    cout << string(48, ' ') << "Movie has been inserted successfully!\n\n";
    cout << string(35, ' ') << "=============================================================================\n";
}

void MovieStore::ReturnMovie()
{
    cout << "\n\n\n\n\n\n\n\n\n\n\n";
    cout << string(35, ' ') << "=============================================================================\n";
    cout << string(64, ' ') << "RETURN A MOVIE\n";
    cout << string(35, ' ') << "=============================================================================\n\n";

    int movieCode;
    cout << string(48, ' ') << "Enter the movie code: ";
    cin >> movieCode;

    auto movie = GetVideo(movieCode);
    if (!movie)
    {
        cout << endl;
        cout << string(48, ' ') << "Movie not found!\n\n";
        cout << string(35, ' ') << "=============================================================================\n";
        return;
    }

    int customerCode;
    cout << string(48, ' ') << "Enter the customer code: ";
    cin >> customerCode;

    auto customer = GetCustomer(customerCode);
    if (!customer)
    {
    cout << endl;
    cout << string(48, ' ') << "Customer not found!\n\n";
    cout << string(35, ' ') << "=============================================================================\n";
        return;
    }

    ReturnMovie(*customer, *movie);
}

void MovieStore::ShowMovieDetails()
{
    cout << "\n\n\n\n\n\n\n\n\n\n\n";
    cout << string(35, ' ') << "=============================================================================\n";
    cout << string(64, ' ') << "SHOW MOVIE DETAILS\n";
    cout << string(35, ' ') << "=============================================================================\n\n";

    int movieCode;
    cout << string(48, ' ') << "Enter the movie code: ";
    cin >> movieCode;

    auto movie = GetVideo(movieCode);
    if (!movie)
    {
    cout << endl;
    cout << string(48, ' ') << "Movie not found!\n\n";
    cout << string(35, ' ') << "=============================================================================\n";
        return;
    }

    ShowMovieDetails(*movie);
}

void MovieStore::CheckVideoAvailability()
{
    cout << "\n\n\n\n\n\n\n\n\n\n\n";
    cout << string(35, ' ') << "=============================================================================\n";
    cout << string(64, ' ') << "CHECK MOVIE AVAILABILITY\n";
    cout << string(35, ' ') << "=============================================================================\n\n";

    int movieCode;
    cout << string(48, ' ') << "Enter the movie code: ";
    cin >> movieCode;

    auto movie = GetVideo(movieCode);
    if (!movie)
    {
        cout << endl;
        cout << string(48, ' ') << "Movie not found!\n\n";
        cout << string(35, ' ') << "=============================================================================\n";
    }
    else if (movie->Copies > 0)
    {
    cout << endl;
    cout << string(48, ' ') << "Movie is available!\n\n";
    cout << string(35, ' ') << "=============================================================================\n";
    }
    else
    {
        cout << endl;
        cout << string(48, ' ') << "Movie not available!\n\n";
        cout << string(35, ' ') << "=============================================================================\n";
    }
}

void MovieStore::CustomerMaintenance()
{
    cout << "\n\n\n\n\n\n\n\n\n\n\n";
    cout << string(35, ' ') << "=============================================================================\n";
    cout << string(64, ' ') << "CUSTOMER MAINTENANCE\n";
    cout << string(35, ' ') << "=============================================================================\n\n";
    cout << string(48, ' ') << "[1] Add New Customer\n";
    cout << string(48, ' ') << "[2] Customer Details\n";
    cout << string(48, ' ') << "[3] List of Movies Rented\n";
    cout << string(35, ' ') << "==========================================================================================\n";

    int choice;
    cout << string(35, ' ') << "Please choose an option... ";
    cin >> choice;

    system("clear||cls");

    if (choice == 1)
    {
        cout << "\n\n\n\n\n\n\n\n\n\n\n";
        cout << string(35, ' ') << "=============================================================================\n";
        cout << string(64, ' ') << "ADD A NEW CUSTOMER\n";
        cout << string(35, ' ') << "=============================================================================\n\n";

        int count = customerQueue.size() + 1;

        cout << string(48, ' ') << "Customer ID : " << count;

        string name;
        cin.ignore();
        cout << "\n\n" << string(48, ' ') << "Name        : ";
        getline(cin, name);

        string address;
        cout << '\n' << string(48, ' ') << "Address     : ";
        getline(cin, address);

        customerQueue.push_back({count, name, address});

        cout << "\n\n" << string(48, ' ') << "New Customer Added Successfully!\n" << endl;
        cout << string(35, ' ') << "=============================================================================\n";
    }
    else if (choice == 2)
    {
        cout << "\n\n\n\n\n\n\n\n\n\n\n";
        cout << string(35, ' ') << "=============================================================================\n";
        cout << string(64, ' ') << "SHOW CUSTOMER DETAILS\n";
        cout << string(35, ' ') << "=============================================================================\n\n";

        int customerCode;
        cout << string(48, ' ') << "Enter the customer code: ";
        cin >> customerCode;

        auto customer = GetCustomer(customerCode);
        if (!customer)
        {
            cout << "\n\n" << string(48, ' ') << "Customer not found!\n" << endl;
            cout << string(35, ' ') << "=============================================================================\n";
            return;
        }

        ShowCustomerDetails(*customer);
    }
    else if (choice == 3)
    {
        cout << "\n\n\n\n\n\n\n\n\n\n\n";
        cout << string(35, ' ') << "=============================================================================\n";
        cout << string(64, ' ') << "LIST ALL VIDEOS RENTED BY A CUSTOMER\n";
        cout << string(35, ' ') << "=============================================================================\n\n";

        int customerCode;
        cout << string(48, ' ') << "Enter the customer code: ";
        cin >> customerCode;

        auto customer = GetCustomer(customerCode);
        if (!customer)
        {
            cout << "\n\n" << string(48, ' ') << "Customer not found!\n" << endl;
            cout << string(35, ' ') << "=============================================================================\n";
            return;
        }

        auto movies = GetMoviesByCustomer(*customer);

        ShowCustomerDetails(*customer);
        DisplayMovies(movies);
    }
    else
    {
        cout << "\n\n" << string(48, ' ') << "Invalid entry! Please try again... \n" << endl;
        cout << string(35, ' ') << "=============================================================================\n";
    }
}

void MovieStore::RentMovie()
{
    cout << "\n\n\n\n\n\n\n\n\n\n\n";
    cout << string(35, ' ') << "=============================================================================\n";
    cout << string(66, ' ') << "RENT A MOVIE\n";
    cout << string(35, ' ') << "=============================================================================\n\n";

    int movieCode;
    cout << string(48, ' ') << "Enter the movie code: ";
    cin >> movieCode;

    auto movie = GetVideo(movieCode);
    if (!movie)
    {
        cout << "\n\n" << string(48, ' ') << "Movie not found!\n" << endl;
        cout << string(35, ' ') << "=============================================================================\n";
        return;
    }

    int customerCode;
    cout << '\n' << string(48, ' ') << "Enter the customer code: ";
    cin >> customerCode;

    auto customer = GetCustomer(customerCode);
    if (!customer)
    {
        cout << "\n\n" << string(48, ' ') << "Customer not found!\n\n" << endl;
        cout << string(35, ' ') << "=============================================================================\n";
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
        cout << '\n' << string(48, ' ') << "Movie has been rented successfully!\n\n";
        cout << string(35, ' ') << "=============================================================================\n";

        return true;
    }

        cout << '\n' << string(48, ' ') << "Movie is out of stock!\n\n";
        cout << string(35, ' ') << "=============================================================================\n";

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
            cout << '\n' << string(48, ' ') << "Movie has been returned successfully!\n";
            cout << string(35, ' ') << "=============================================================================\n";
            return true;
        }
    }

    cout << '\n' << string(48, ' ') << "Movie is not rented by this customer!\n";
    cout << string(35, ' ') << "=============================================================================\n";
    return false;
}

void MovieStore::ShowMovieDetails(VideoAdt& video)
{
    cout << left;
    cout << "======================================================================================================================\n";
    cout << string(40, ' ') << "DISPLAY ALL MOVIEs\n";
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
    cout << string(40, ' ') << "DISPLAY CUSTOMER\n";
    cout << "======================================================================================================================\n";
    cout << setw(5) << "ID" << setw(10) << "NAME" << "ADDRESS" << endl;
    cout << "======================================================================================================================\n";

    cout << setw(5) << video.Id;
    cout << setw(10) << video.Name;
    cout << video.Address << endl << endl;
}

vector<VideoAdt> MovieStore::GetMoviesByCustomer(CustomerAdt& customer)
{
    vector<VideoAdt> movies;
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

    videoList = j.get<vector<VideoAdt>>();
    sort(videoList.begin(), videoList.end());
}

void MovieStore::OpenRentFile()
{
    ifstream openRent("Rent.json");

    json j;
    openRent >> j;

    rentList = j.get<vector<RentAdt>>();
}

//Open Customer File - Programmer 1
void MovieStore::OpenCustomerFile()
{
    ifstream openCust("Customers.json");

    json j;
    openCust >> j;

    customerQueue = j.get<deque<CustomerAdt>>();
}