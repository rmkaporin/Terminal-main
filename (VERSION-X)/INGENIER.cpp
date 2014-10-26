/***********************************************************************
 * Module:  Engineer.cpp
 * Author:  Roman Kaporin
 * Modified: 01 October 2014 20:35:17
 * Purpose: Implementation of the class Engineer
 * Comment: !It's object that repear terminal
 ***********************************************************************/
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
using namespace std;

#include "Engineer.h"

////////////////////////////////////////////////////////////////////////
// Name:       parsLookColmn(char* str, int colmn)
// Purpose:    Implementation of parsLookColmn(char* str, int colmn)
// Comment:    Looks for one word in string
// Return:     
////////////////////////////////////////////////////////////////////////

char* parsLookColmn(char* str, int colmn) {
	char * delim = strtok(str, " ");
	for (int i = 0; i < colmn - 1; i++)
		delim = strtok(NULL, " ");
	return delim;
}

////////////////////////////////////////////////////////////////////////
// Name:       Engineer::parsComputer()
// Purpose:    Implementation of Engineer::parsComputer()
// Comment:    Check status of Computer by reading it's status in log file
// Return:     
////////////////////////////////////////////////////////////////////////

void Engineer::readAndFixComputer(char *str, Computer &computer) {
	char* strForPars = parsLookColmn(str, 5);	//Look for status of Computer
	if (strcmp(strForPars, "false")) { //Repeare if broken
		computer.cpu          =	true;	//CPU
		computer .display     = true;	//Display
		computer .hdd         = true;	//HDD
		computer .motherboard = true;	//Motherboard
		computer .netAdapter  = true;	//Network adapter
	}	
}

////////////////////////////////////////////////////////////////////////
// Name:       Engineer::parsPrinter(char *)
// Purpose:    Implementation of Engineer::parsPrinter(char *)
// Comment:    Looking for errors with Printer
// Return:     
////////////////////////////////////////////////////////////////////////

void Engineer::readAndFixPrinter(char *str, Printer &printer) {
	char* strForPars = parsLookColmn(str, 5);	//Look for status of Computer
	if (strcmp(strForPars, "false")) {	//Repeare if broken
		printer.statusOfInk = 100;
		printer.statusOfPaper = 100;
	}
}

////////////////////////////////////////////////////////////////////////
// Name:       Engineer::parsCashbox()
// Purpose:    Implementation of Engineer::parsCashbox()
// Comment:    Looking for errors with Cashbox
// Return:     
////////////////////////////////////////////////////////////////////////

void Engineer::readAndFixCashbox(char *str, Cashbox &cashbox) {
	char* strForPars = parsLookColmn(str, 5);	//Look for status of Computer
	if (strcmp(strForPars, "false")) {
		money = cashbox . cashNow;	//Take money from Cashbox 
		cashbox . cashNow = NULL;		//Cashbox is empty
	}
}

////////////////////////////////////////////////////////////////////////
// Name:       Engineer::logAnalitic()
// Purpose:    Implementation of Engineer::logAnalitic()
// Comment:    Analize status of terminal
// Return:     
////////////////////////////////////////////////////////////////////////

void Engineer::logAnalitic() {
	if (adressForSupport != nullptr) {
		//=================== Counter of stings in log.txt ================================//
		int count = -1;						//Counter of strings - (-1) because, 
											//the last string in file is empty but exist

		ifstream preLog ("log.txt");		//Open file with dirrections for counting them
		if (preLog.is_open()) {						//If we can open file, then
			do {									//While we can read
				char buffer[100];						//Buffer for reading
				preLog.getline(buffer, 100);				//Read line
				count++;							//Count++
			} while(preLog.good());
			preLog.close();						//Close file
		}
		else {									//If some thing wrong - go away
			cout << "File doesn't exist!" << endl;
			exit(0);
		}
		cout << "Number of strings - " << count << endl;
		//=================================================================================//

		//=================== Parsing of last three strings ===============================//
		ifstream log ("log.txt");
		for (int i = 0; i <= count - 1; i++) {
			char buffer[100];
			log.getline(buffer, 100);
			if (i == count - 3) readAndFixComputer(buffer, adressForSupport -> m_Computer);		//Last status of Computer
			if (i == count - 2) readAndFixPrinter (buffer, adressForSupport -> m_Printer);		//Last status of Printer
			if (i == count - 1) readAndFixCashbox (buffer, adressForSupport -> m_Cashbox);		//Last status of Cashbox
		}
		log.close();
		//=================================================================================//
	}
	else {
		cout << "UNKNOW ADRESS OF TERMINAL!!!" <<endl;
	}
}

////////////////////////////////////////////////////////////////////////
// Name:       Engineer::Engineer()
// Purpose:    Implementation of Engineer::Engineer()
// Comment:    !Standart constructor
// Return:     
////////////////////////////////////////////////////////////////////////

Engineer::Engineer() //!Standart constructor
	: money(NULL),					//Starting value of money, that was picked up by Engineer
	  adressForSupport(nullptr)		//At start we don't know adress of terminal
{
#if (TEST == 1)
		cout << "'Engineer' - Standart constructor already started FROM DEFAULT!" << endl;
#endif
}

////////////////////////////////////////////////////////////////////////
// Name:       Engineer::takeTerminalAdress(Terminal *)
// Purpose:    Implementation of Engineer::takeTerminalAdress(Terminal *)
// Comment:    !Take adress of terminal for repear
// Return:     
////////////////////////////////////////////////////////////////////////

void Engineer::takeTerminalAdress(Terminal *adress) {
	adressForSupport = adress;	//Taking adress of Terminal
	#if (TEST == 1)
		cout << "Adress of Terminal - " << adressForSupport << endl;
	#endif
}