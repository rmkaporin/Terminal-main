/***********************************************************************
 * Module:  Server.h
 * Author:  Roman Kaporin
 * Modified: 01 October 2014 20:39:15
 * Purpose: Declaration of the class Server
 ***********************************************************************/

#if !defined(__Terminal_class_Server_h)
#define __Terminal_class_Server_h

#include "define.h"

class Terminal;

class Server
{
	struct dirrection {	//!Structor of dirrection
	char source[20];		//!Source
	char destenation[20];	//!Destenation
	char time[20];			//!Date
	int numOfTickets;		//!Number of available tickets
	float coast;			//!Coast of one ticket
   };

public:
   
   int dataSearch(void);	//!Searching tickets in DB and returns index of dirrection (number of direction = index of dirrection in array)
   bool ticketCreate(void); //!Creats ticket for user and ends users registration
   void ticketBackUp(void); //!Bacups all tickets in files
   void dirrOutput(void);   //!Output all available dirrecction
   Server();							 //!Standart constructor
   Server(dirrection* pointer, int dir); //!Constructor with initialization
   ~Server();							 //!Destructor

   Terminal** Terminal;

protected:
private:

   void dataEdit(void);    //!Editing number of tickets in dirrection after registration
   dirrection* listOfDir; //!List with available dirrections

   int numOfAcc;	//!NUmber of passanger's accounts
   int numOfDirr;	//!Number of dirrections


};

#endif