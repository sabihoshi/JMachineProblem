#pragma once
#include <deque>
#include <fstream>
#include <iostream>
#include <list>
#include <sstream>
#include <stack>
#include <string>

#include "json.hpp"

using namespace std;
//programmer 1

//Responsible for movie data
struct VideoAdt
{
    int Id;
    int Copies;
    string Title;
    string Genre;
    string Production;
    string Image;

    NLOHMANN_DEFINE_TYPE_INTRUSIVE(VideoAdt, Id, Copies, Title, Genre, Production, Image)
};

//Responsible for customer data
struct CustomerAdt
{
    int Id;
    string Name;
    string Address;

    NLOHMANN_DEFINE_TYPE_INTRUSIVE(CustomerAdt, Id, Name, Address)
};

struct RentAdt
{
    int CustomerId;
    int VideoId;

    NLOHMANN_DEFINE_TYPE_INTRUSIVE(RentAdt, CustomerId, VideoId)

    bool operator==(const RentAdt& other) const
    {
        return CustomerId == other.CustomerId && VideoId == other.VideoId;
    }
};

// Handles All Function
class MovieStore
{
private:
    deque<CustomerAdt> customerQueue;
    list<VideoAdt> videoList;
    list<RentAdt> rentList;

public:
    MovieStore();

    void DisplayMovies();

    //Movie/files function
    void AddMovie();

    bool RentMovie(CustomerAdt& customer, VideoAdt& video);

    bool ReturnMovie(CustomerAdt& customer, VideoAdt& video);

    static void ShowMovieDetails(VideoAdt& video);

    static void ShowCustomerDetails(CustomerAdt& video);

    list<VideoAdt> GetMoviesByCustomer(CustomerAdt& customer);

    CustomerAdt* GetCustomer(int id);

    VideoAdt* GetVideo(int id);

    void DisplayMovies(list<VideoAdt>& movies);


    void SaveMovieFile();
    void SaveCustomerFile();
    void SaveRentFile();

    //Customer/files function
    bool IsCustomerEmpty();

    void AddCustomer();

    void OpenCustomerFile();
    void OpenMovieFile();
    void OpenRentFile();
};