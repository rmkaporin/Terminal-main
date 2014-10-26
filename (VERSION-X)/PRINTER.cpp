/***********************************************************************
 * Module:  Printer.cpp
 * Author:  Roman Kaporin
 * Modified: 01 October 2014 20:37:15
 * Purpose: Implementation of the class Printer
 ***********************************************************************/
#include <iostream>
#include <fstream>
using namespace std;

#include "Printer.h"

////////////////////////////////////////////////////////////////////////
// Name:       Printer::printTicket()
// Purpose:    Implementation of Printer::printTicket()
// Comment:    !Printig tickets and bills after ticket's registration(check ability of printing before printing)
// Return:     bool
////////////////////////////////////////////////////////////////////////

bool Printer::printTicket(void)
{
   // TODO : implement
	return 0;
}

////////////////////////////////////////////////////////////////////////
// Name:       Printer::selfCheck()
// Purpose:    Implementation of Printer::selfCheck()
// Comment:    !Looking for problems with Printer
// Return:     bool
////////////////////////////////////////////////////////////////////////

bool Printer::selfCheck(){	//Looking for problems with Printer
	if (statusOfInk < 10 || statusOfPaper < 10) //If something wrong
		return false;		//Report about error
	else 
		return true;		//Else say, that all is OK 
}

////////////////////////////////////////////////////////////////////////
// Name:       Printer::Printer()
// Purpose:    Implementation of Printer::Printer()
// Comment:    !Standart constructor
// Return:     
////////////////////////////////////////////////////////////////////////

Printer::Printer()				//!Standart constructor
{
	ifstream conf ("printC.txt");	//Open conf file of Printer

	if (conf.good()) {			//If we can read file, then
		char buf[10];				//Buffer for config data

		conf.getline(buf, 10);		//Get inf. about start status of ink
		statusOfInk = atof(buf);

		conf.getline(buf, 10);		//Get inf. about start status of paper
		statusOfPaper = atoi(buf); 

		conf.close();

		cout << "'Printer' - Standart constructor already started FROM FILE!" << endl;
	}
	else {						//If we can't, then 
		statusOfInk = 100;
		statusOfPaper = 1000;
		cout << "'Printer' - Standart constructor already started FROM DEFAULT!" << endl;
	}
}

////////////////////////////////////////////////////////////////////////
// Name:       Printer::Printer()
// Purpose:    Implementation of Printer::Printer()
// Comment:    !Constructor with initialization
// Return:     
////////////////////////////////////////////////////////////////////////

Printer::Printer(int paper, float ink)
	: statusOfPaper(paper),
	  statusOfInk(ink)
{
	cout << "'Printer' - Constructor with initialization already started! " <<endl;
}
