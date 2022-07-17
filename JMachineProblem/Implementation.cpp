#include <iomanip>
#include <iostream>
#include <string>

#include "Data.h"
using namespace std;
using namespace nlohmann;

MovieStore::MovieStore() {}

void MovieStore::DisplayMovies()
{
    DisplayMovies(videoList);
}

//Display All Movies - Programmer 1
void MovieStore::DisplayMovies(list<VideoAdt>& movies)
{
    cout << "\n\n";
    cout << " ======================================================================================================================\n";
    cout << string(30, ' ') << "DISPLAY MOVIES\n";
    cout << " ======================================================================================================================\n\n";
    cout << " " << setw(5) << "ID" << setw(10) << "TITLE" << setw(30) << "GENRE" << setw(30) << "PRODUCTION" << "NO. OF COPIES\n";
    cout << " ======================================================================================================================\n";
    for (auto& video : movies)
    {
        cout << " " << setw(5) << video.Id;
        cout << setw(10) << video.Title;
        cout << setw(30) << video.Genre;
        cout << setw(30) << video.Production;
        cout << video.Copies << endl << endl;
    }
}

//Add Customer - Programmer 1
void MovieStore::AddCustomer()
{
    int count = customerQueue.size() + 1;
    string CustomerName, CustomerAddress;

    cout << '\n' << string(35, ' ') << "Enter Customer Details" << endl;
    cout << string(35, ' ') << "Code: " << count;

    cin.ignore();
    cout << string(35, ' ') << "Name: ";
    getline(cin, CustomerName);

    cout << string(35, ' ') << "Address: ";
    getline(cin, CustomerAddress);

    customerQueue.push_back({count, CustomerName, CustomerAddress});

    cout << "\n\n" << string(35, ' ') << "New Customer Added Successfully!\n" << endl;
    cout << string(112, ' ') << "=============================================================================\n";
}

//Add Movie - Programmer 1
void MovieStore::AddMovie()
{
    int count = videoList.size() + 1;

    cout << '\n' << string(35, ' ') << "Enter Movie Details" << endl;
    cout << string(35, ' ') << "Code: " << count;

    cout << string(35, ' ') << "Title: ";
    string title;
    cin.ignore();
    getline(cin, title);

    cout << string(35, ' ') << "Genre: ";
    string genre;
    getline(cin, genre);

    cout << string(35, ' ') << "Producer: ";
    string producer;
    getline(cin, producer);

    cout << string(35, ' ') << "Image: ";
    string image;
    getline(cin, image);

    int copies;
    cout << string(35, ' ') << "Copies: ";
    cin >> copies;

    videoList.push_back({count, copies, title, genre, producer, image});

    cout << string(50, ' ') << "Movie has been inserted successfully!\n";
    cout << string(30, ' ') << "=============================================================================\n";
}

bool MovieStore::RentMovie(CustomerAdt& customer, VideoAdt& video)
{
    if (video.Copies > 0)
    {
        video.Copies--;
        rentList.push_back({customer.Id, video.Id});
        cout << "\n\n" << string(50, ' ') << "Movie has been rented successfully!\n";
        cout << string(30, ' ') << "=============================================================================\n";
        return true;
    }
    cout << "\n\n" << string(50, ' ') << "Movie is out of stock!\n";
    cout << string(30, ' ') << "=============================================================================\n";
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
            cout << "\n\n" << string(50, ' ') << "Movie has been returned successfully!\n";
            cout << string(30, ' ') << "=============================================================================\n";
            return true;
        }
    }

    cout << "\n\n" << string(50, ' ') << "Movie is not rented by this customer!\n";
    cout << string(30, ' ') << "=============================================================================\n";
    return false;
}

void MovieStore::ShowMovieDetails(VideoAdt& video)
{
    cout << "\n\n";
    cout << " ======================================================================================================================\n";
    cout << string(30, ' ') << "DISPLAY MOVIE\n";
    cout << " ======================================================================================================================\n\n";
    cout << " " << setw(5) << "ID" << setw(10) << "TITLE" << setw(30) << "GENRE" << setw(30) << "PRODUCTION" << "NO. OF COPIES\n";
    cout << " ======================================================================================================================\n";

    cout << " " << setw(5) << video.Id;
    cout << setw(10) << video.Title;
    cout << setw(30) << video.Genre;
    cout << setw(30) << video.Production;
    cout << video.Copies << endl << endl;
}

void MovieStore::ShowCustomerDetails(CustomerAdt& video)
{
    cout << "\n\n";
    cout << " ======================================================================================================================\n";
    cout << string(30, ' ') << "DISPLAY CUSTOMER\n";
    cout << " ======================================================================================================================\n\n";
    cout << " " << setw(5) << "ID" << setw(10) << "NAME" << "ADDRESS" << endl;
    cout << " ======================================================================================================================\n";

    cout << " " << setw(5) << video.Id;
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

bool MovieStore::IsCustomerEmpty()
{
    if (customerQueue.empty())
    {
        cout << "Invalid Customer ID! " << endl;
        return true;
    }
    return false;
}
