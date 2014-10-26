/***********************************************************************
 * Module:  Server.cpp
 * Author:  Roman Kaporin
 * Modified: 01 October 2014 20:39:15
 * Purpose: Implementation of the class Server
 ***********************************************************************/
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

#include "Terminal.h"
#include "Server.h"

////////////////////////////////////////////////////////////////////////
// Name:       Server::dataSearch()
// Purpose:    Implementation of Server::dataSearch()
// Comment:    !Searching tickets in DB and returns index of dirrection (number of direction = index of dirrection in array)
// Return:     int
////////////////////////////////////////////////////////////////////////

int Server::dataSearch(void)
{
   // TODO : implement
	return 0;
}

////////////////////////////////////////////////////////////////////////
// Name:       Server::dataEdit()
// Purpose:    Implementation of Server::dataEdit()
// Comment:    !Editing number of tickets in dirrection after registration
// Return:     void
////////////////////////////////////////////////////////////////////////

void Server::dataEdit(void)
{
   // TODO : implement
}

////////////////////////////////////////////////////////////////////////
// Name:       Server::ticketCreate()
// Purpose:    Implementation of Server::ticketCreate()
// Comment:    !Creats ticket for user and ends users registration
// Return:     bool
////////////////////////////////////////////////////////////////////////

bool Server::ticketCreate(void)
{
   // TODO : implement
	return 0;
}

////////////////////////////////////////////////////////////////////////
// Name:       Server::ticketBackUp()
// Purpose:    Implementation of Server::ticketBackUp()
// Comment:    !Bacups all tickets in files
// Return:     void
////////////////////////////////////////////////////////////////////////

void Server::ticketBackUp(void)
{
   // TODO : implement
}

////////////////////////////////////////////////////////////////////////
// Name:       Server::dirrOutput()
// Purpose:    Implementation of Server::dirrOutput()
// Comment:    !Output all available dirrecction
// Return:     void
////////////////////////////////////////////////////////////////////////

void Server::dirrOutput(void)
{
   	cout << "\t\t\tAVAILABLE DIRRECTIONS" << endl;
	for (int i = 0; i < numOfDirr; i++){
		cout << listOfDir[i].source << setw(20) <<" - " << listOfDir[i].destenation << setw(20);
		cout << " at " << listOfDir[i].time << " have " << listOfDir[i].numOfTickets;
		cout << "seats that coasts" << listOfDir[i].coast << "UAH" << endl;
	}
}

////////////////////////////////////////////////////////////////////////
// Name:       Server::~Server()
// Purpose:    Implementation of Server::~Server()
// Comment:    !Destructor
// Return:     
////////////////////////////////////////////////////////////////////////

Server::~Server()	//!Destructor
{
	if (listOfDir != NULL) delete []listOfDir;
#if (TEST == 1)
	cout << "'Server' - Destructor already finished! " << endl; 
#endif
}

////////////////////////////////////////////////////////////////////////
// Name:       Server::Server()
// Purpose:    Implementation of Server::Server()
// Comment:    !Default constructor
// Return:     
////////////////////////////////////////////////////////////////////////

Server::Server()					//!Standart constructor
{
   Terminal = NULL;		//Pointer to obj. TERMINAL
   listOfDir = NULL; 
   numOfDirr = NULL;

   	ifstream list ("dirrections.txt");		//Open file with dirrections for counting them
	if (list.is_open()) {						//If we can open file, then
		do {									//While we can read
			numOfDirr++;							//Count++
			char buffer[100];						//Buffer for reading
			list.getline(buffer, 100);				//Read line
		} while(list.good());
		list.close();						//Close file
	}
	else {									//If some thing wrong - go away
		cout << "File doesn't exist!" << endl;
		exit(0);
	}

	dirrection *dirr = new dirrection [numOfDirr + 1];	//Creat array of structurs

	ifstream way ("dirrections.txt");		//Open file with dirrections

	for (int i = 0; i < numOfDirr; i++) {	//Get a database 
		char buffer[150];
		char buffer2d[5][20];	//Temp data that consist of dirrection's parametrs
		char delim[] = " \n";
		char *token;

		way.getline(buffer, 150);
		token = strtok(buffer, delim);
		for (int j = 0; j < 5; j++) {
			strcpy(buffer2d[j], token);
			token = strtok (NULL, delim);
		}

		strcpy(dirr[i].source, strupr(buffer2d[0]));		//Get inf. about source
		strcpy(dirr[i].destenation, strupr(buffer2d[1]));	//Get inf. about destenation
		strcpy(dirr[i].time, buffer2d[2]);					//Get time of trip
		dirr[i].numOfTickets = atoi(buffer2d[3]);			//Get number of available tickets
		dirr[i].coast = atof(buffer2d[4]);					//Get number of seats
	}
	way.close();

	listOfDir = dirr;	//Save readed information
#if (TEST == 1)
   cout << "'Server' - Standart constuctor already started! " << endl;
#endif
}

////////////////////////////////////////////////////////////////////////
// Name:       Server::Server(dirrection*, int)
// Purpose:    Implementation of Server::Server(dirrection*, int)
// Comment:    !Constructor with initialization
// Return:     
////////////////////////////////////////////////////////////////////////

Server::Server(dirrection* pointer, int dir) //!Constructor with initialization
{		
	Terminal = NULL; 
	numOfDirr = dir;
	listOfDir = pointer;
}