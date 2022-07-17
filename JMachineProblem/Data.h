#pragma once
#include <string> 
#include <deque> 
#include <stack> 
#include <sstream> 
#include <fstream> 
#include <iostream> 
using namespace std;
//programmer 1

//Responsible for movie data
struct VideoAdt {
    int videoID, copies;
    string Title,
        Genre,
        Production;
};

//Responsible for customer data
struct CustomerAdt {
    int cID;
    string Name, Address;
};

// Handles All Function
class movieList {
private:
    CustomerAdt custlq;
    bool cQcheck = false;
    deque < CustomerAdt > custQueue;

    struct movieListNode {
        VideoAdt movl;
        struct movieListNode* Mnext;
    };

    movieListNode* Moviehead;

public:
    int count, customerCount;
    movieList();
    //Movie/files function
    void addMovie(VideoAdt movl);
    void displayMovies();
    void OpenMovieFile();
    void SaveMovieFile();

    //Customer/files function
    bool isCustomerEmpty();
    void addCustomer(CustomerAdt custl);
    void OpenCustomerFile();
    void SaveCustomerFile();
};