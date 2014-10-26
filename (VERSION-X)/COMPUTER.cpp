/***********************************************************************
 * Module:  Computer.cpp
 * Author:  Roman Kaporin
 * Modified: 01 October 2014 20:36:29
 * Purpose: Implementation of the class Computer
 ***********************************************************************/
#include <fstream>
#include <iostream>
using namespace std;

#include "Computer.h"

////////////////////////////////////////////////////////////////////////
// Name:       Computer::userAcc()
// Purpose:    Implementation of Computer::userAcc()
// Comment:    !Creating account for user in current session
// Return:     void
////////////////////////////////////////////////////////////////////////

void Computer::userAcc(void)
{
   // TODO : implement
}

////////////////////////////////////////////////////////////////////////
// Name:       Computer::userInput()
// Purpose:    Implementation of Computer::userInput()
// Comment:    !User input ticket information for requesting the Server
// Return:     void
////////////////////////////////////////////////////////////////////////

void Computer::userInput(void)
{
   // TODO : implement
}

////////////////////////////////////////////////////////////////////////
// Name:       Computer::userID()
// Purpose:    Implementation of Computer::userID()
// Comment:    !Applying form for registration ticket
// Return:     void
////////////////////////////////////////////////////////////////////////

void Computer::userID(void)
{
   // TODO : implement
}

////////////////////////////////////////////////////////////////////////
// Name:       Computer::receivingRegStart()
// Purpose:    Implementation of Computer::receivingRegStart()
// Comment:    !Receiving information from Server about ticket for user
// Return:     void
////////////////////////////////////////////////////////////////////////

void Computer::receivingRegStart(void)
{
   // TODO : implement
}

////////////////////////////////////////////////////////////////////////
// Name:       Computer::receivingRegEnd()
// Purpose:    Implementation of Computer::receivingRegEnd()
// Comment:    !Registration ticket on Server
// Return:     void
////////////////////////////////////////////////////////////////////////

void Computer::receivingRegEnd(void)
{
   // TODO : implement
}

////////////////////////////////////////////////////////////////////////
// Name:       Computer::Computer()
// Purpose:    Implementation of Computer::Computer()
// Comment:    !Standart constructor
// Return:     
////////////////////////////////////////////////////////////////////////

Computer::Computer()
{
	ifstream conf ("compC.txt");	//Open conf file of Printer

	if (conf.good()) {			//If we can read file, then
		char buf[10];				//Buffer for config data

		netAdapter = display = hdd = motherboard = cpu = false;

		conf.getline(buf, 10);		//Get inf. about start status of motherboard
		if (!strcmp(buf,"true")) motherboard = true;

		conf.getline(buf, 10);		//Get inf. about start status of cpu
		if (!strcmp(buf,"true")) cpu = true;

		conf.getline(buf, 10);		//Get inf. about start status of hdd
		if (!strcmp(buf,"true")) hdd = true;

		conf.getline(buf, 10);		//Get inf. about start status of display
		if (!strcmp(buf,"true")) display = true;

		conf.getline(buf, 10);		//Get inf. about start status of NetAdapter
		if (!strcmp(buf,"true")) netAdapter = true;

		conf.close();

		cout << "'Computer' - Standart constructor already started FROM FILE!" << endl;
	}
	else {
		netAdapter = display = hdd = motherboard = cpu = true;
		cout << "'Computer' - Standart constuctor has already started - FROM DEFAULT! " <<endl;
	}
}

////////////////////////////////////////////////////////////////////////
// Name:       Computer::Computer()
// Purpose:    Implementation of Computer::Computer()
// Comment:    !Constructor with initialization
// Return:     
////////////////////////////////////////////////////////////////////////

Computer::Computer(bool dspl, bool cpu, bool mbrd, bool hdd, bool net)
	: display(dspl),		//Display config.
	  cpu(cpu),				//CPU config
	  motherboard(mbrd),	//Motherboard config
	  hdd(hdd),				//HDD config
	  netAdapter(net)		//NetAdapter config
{
	cout << "'Computer' - Constructor with initialization already started! " << endl;
}

////////////////////////////////////////////////////////////////////////
// Name:       Computer::Computer()
// Purpose:    Implementation of Computer::Computer()
// Comment:    !Constructor with initialization
// Return:     
////////////////////////////////////////////////////////////////////////

bool Computer::BIOS() {
#if (TEST == 1)
	cout << "\t\t\t Terminal BIOS v.1 - 2014" <<endl;

	cout << "\t\t\t Testing Computer's systems" <<endl;
	cout << "Status of Motherboard - " << boolalpha << motherboard		<<endl;	
	cout << "Status of CPU         - " << boolalpha << cpu				<<endl;
	cout << "Status of HDD         - " << boolalpha << hdd				<<endl;
	cout << "Status of Net adapter - " << boolalpha << netAdapter		<<endl;
	cout << "Status of Display     - " << boolalpha << display	<< "\a"	<<endl;
#endif

	if (motherboard != true || cpu != true || hdd != true || netAdapter != true || display != true) return false;
	else return true;
			
}
