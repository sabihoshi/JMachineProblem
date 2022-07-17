#include <iomanip>
#include <iostream>
#include <string>

#include "Data.h"
using namespace std;

movieList::movieList()
{
	count = 0;
	customerCount = 0;
	Moviehead = nullptr;
}

//Display All Movies - Programmer 1
void movieList::displayMovies()
{
	cout << "\n\n";
	cout << " ======================================================================================================================\n";
	cout << setw(60) << "DISPLAY MOVIES\n";
	cout << " ======================================================================================================================\n\n";
	cout << "ID" << setw(10) << "TITLE" << setw(30) << "GENRE" << setw(30) << "PRODUCTION" << setw(40) << "NO. OF COPIES\n";
	cout << " ======================================================================================================================\n\n";
	movieListNode* MovieFile;
	MovieFile = Moviehead;
	while (MovieFile)
	{
		cout << left << setw(5) << MovieFile->movl.videoID;
		cout << left << setw(30) << MovieFile->movl.Title;
		cout << left << setw(20) << MovieFile->movl.Genre;
		cout << left << setw(40) << MovieFile->movl.Production;
		cout << left << "\t\t" << MovieFile->movl.copies << endl << endl;
		MovieFile = MovieFile->Mnext;
		if (MovieFile == nullptr)
		{
			break;
		}
	}
}

//Add Customer - Programmer 1
void movieList::addCustomer(CustomerAdt custl)
{
	customerCount++;
	string CustomerName, CustomerAddress;
	cQcheck = true;

	cout << '\n' << setw(75) << "Enter Customer Details" << endl;
	cout << '\n' << setw(60) << "Code: " << customerCount;
	custlq.cID = customerCount;
	cin.ignore();
	cout << '\n' << setw(60) << "Name: ";
	getline(cin, CustomerName);
	custlq.Name = CustomerName;
	cout << '\n' << setw(63) << "Address: ";
	getline(cin, CustomerAddress);
	custlq.Address = CustomerAddress;
	custQueue.push_back(custlq);
	cout << "\n\n" << setw(93) << "New Customer Added Successfully!\n" << endl;
	cout << setw(112) << "=============================================================================\n";
}

//Add Movie - Programmer 1
void movieList::addMovie(VideoAdt movl)
{
	count++;
	int Moviecode;
	string Movietitle, Moviegenre, Movieproducer;
	int Moviecopies;

	cout << '\n' << setw(73) << "Enter Movie Details" << endl;
	cout << '\n' << setw(60) << "Code: " << count;
	cin.ignore();
	cout << '\n' << setw(61) << "Title: ";
	getline(cin, Movietitle);
	cout << '\n' << setw(61) << "Genre: ";
	getline(cin, Moviegenre);
	cout << '\n' << setw(64) << "Producer: ";
	getline(cin, Movieproducer);
	cout << '\n' << setw(62) << "Copies: ";
	cin >> Moviecopies;
	cin.ignore();
	cout << endl;
	movieListNode* movnodePtr;
	movieListNode* movnewNode;
	movnewNode = new movieListNode;
	movnewNode->movl.videoID = count;
	movnewNode->movl.Title = Movietitle;
	movnewNode->movl.Genre = Moviegenre;
	movnewNode->movl.Production = Movieproducer;
	movnewNode->movl.copies = Moviecopies;
	movnewNode->Mnext = nullptr;
	if (!Moviehead)
	{
		Moviehead = movnewNode;
	}
	else
	{
		movnodePtr = Moviehead;
		while (movnodePtr->Mnext)
		{
			movnodePtr = movnodePtr->Mnext;
		}
		movnodePtr->Mnext = movnewNode;
	}
	ofstream smf("Movies.txt", ios::app);
	if (smf.is_open())
	{
		smf << movnewNode->movl.videoID << endl;
		smf << movnewNode->movl.Title << endl;
		smf << movnewNode->movl.Genre << endl;
		smf << movnewNode->movl.Production << endl;
		smf << movnewNode->movl.copies << endl;
		smf.close();
	}
	cout << "\n\n" << setw(93) << "Movie has been inserted successfully!\n" << endl;
	cout << setw(112) << "=============================================================================\n";
}

//Save Movie File - Programmer 1
void movieList::SaveMovieFile()
{
	ofstream mdata;
	mdata.open("Movies.txt");
	movieListNode* saveMfile;
	saveMfile = Moviehead;
	while (saveMfile != nullptr)
	{
		mdata << saveMfile->movl.videoID;
		mdata << endl;
		mdata << saveMfile->movl.Title;
		mdata << endl;
		mdata << saveMfile->movl.Genre;
		mdata << endl;
		mdata << saveMfile->movl.Production;
		mdata << endl;
		mdata << saveMfile->movl.copies;
		mdata << endl << endl;
		saveMfile = saveMfile->Mnext;
	}
}

//Save Customer File - Programmer 1
void movieList::SaveCustomerFile()
{
	deque<CustomerAdt>::iterator i;
	ofstream cdata("Customers.txt");
	for (i = custQueue.begin() + 1; i != custQueue.end(); ++i)
	{
		if (cdata.is_open())
		{
			cdata << "ID: " << i->cID << endl;
			cdata << "Name: " << i->Name << endl;
			cdata << "Address: " << i->Address << endl;
			cdata << endl;
		}
	}
	cdata.close();
}

//Opening Movie File - Programmer 1
void movieList::OpenMovieFile()
{
	ifstream openMov;
	openMov.open("Movies.txt");
	movieListNode* movnewNode;
	movieListNode* openFilePtr = Moviehead;
	string readData, movdata1, movdata2, movdata3, movdata4;
	stringstream open1;
	stringstream open2;
	int mov_Code;
	int mov_Copies;
	int c = 0;
	while (getline(openMov, readData))
	{
		if (c == 0)
		{
			open1 << readData;
			open1 >> mov_Code;
			c++;
		}
		else if (c == 1)
		{
			movdata1 = readData;
			c++;
		}
		else if (c == 2)
		{
			movdata2 = readData;
			c++;
		}
		else if (c == 3)
		{
			movdata3 = readData;
			c++;
		}
		else if (c == 4)
		{
			open2 << readData;
			open2 >> mov_Copies;
			c++;
		}
		else
		{
			movdata4 = readData;
			movnewNode = new movieListNode;
			movnewNode->movl.videoID = mov_Code;
			movnewNode->movl.Title = movdata1;
			movnewNode->movl.Genre = movdata2;
			movnewNode->movl.Production = movdata3;
			movnewNode->movl.copies = mov_Copies;
			c = 0;
			movnewNode->Mnext = nullptr;
			if (!Moviehead)
			{
				Moviehead = movnewNode;
				openFilePtr = Moviehead;
			}
			else
			{
				openFilePtr->Mnext = movnewNode;
				openFilePtr = openFilePtr->Mnext;
			}
		}
		open1.clear();
		open2.clear();
	}
	openMov.close();
}

//Open Customer File - Programmer 1
void movieList::OpenCustomerFile()
{
	int custCurr = 0;
	ifstream openCust("Customers.txt");
	while (openCust)
	{
		if (cQcheck == true)
		{
			break;
		}
		openCust >> custlq.cID;
		openCust.ignore();
		if (custlq.cID == custCurr)
		{
			break;
		}
		custCurr = custlq.cID;
		getline(openCust, custlq.Name);
		getline(openCust, custlq.Address);
		openCust.ignore();
		custQueue.push_back(custlq);
	}
	cQcheck = true;
	openCust.close();
}

bool movieList::isCustomerEmpty()
{
	if (custQueue.empty())
	{
		cout << "Invalid Customer ID! " << endl;
		return true;
	}
	return false;
}
