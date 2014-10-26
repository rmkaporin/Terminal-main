/***********************************************************************
 * Module:  Terminal.cpp
 * Author:  Roman Kaporin
 * Modified: 01 October 2014 20:41:18
 * Purpose: Implementation of the class Terminal
 * Comment: !This class is main for modelling of terminal. It consist of three parts: Computer, Cashbox and Printer.
 ***********************************************************************/
#include <iostream>
#include <fstream>
#include <ctime>
using namespace std;

#include "Server.h"
#include "Terminal.h"

////////////////////////////////////////////////////////////////////////
// Name:       Terminal::systemCheck()
// Purpose:    Implementation of Terminal::systemCheck()
// Comment:    !Downloaded start configuration of system status at starting
// Return:     void
////////////////////////////////////////////////////////////////////////

void Terminal::systemCheck(void)
{
#if (TEST == 1)
   //======================== MUST BE DELETED AFTER TESTING ==============//
   cout << "Look for errors... " << endl;
   cout << "Touch Printer : " << boolalpha << m_Printer.selfCheck() << endl;
   cout << "Touch Computer: " << boolalpha << m_Computer.BIOS()		<< endl;
   cout << "Touch Cashbox : " << boolalpha << m_Cashbox.cashAdd(0)  << endl;
   //======================================================================//
#endif



   char* elements[] = {"Computer", "Printer", "Cashbox"}; //Names of elements
   bool statistic[3];	//0 - about Computer
						//1 - about Printer
						//2 - about Cashbox

   //======== Retraiving information about terminal's elements ======//
   statistic[0] = m_Computer.BIOS();		//Get status of Computer
   statistic[1] = m_Printer.selfCheck();	//Get status of Printer
   statistic[2] = m_Cashbox.cashAdd(0);		//Get status of Cashbox
   //================================================================//

   time_t result = time(nullptr);

	ofstream logfile ("log.txt", ios::app);	//Writing to logfile
	for (size_t i = 0; i < 3; i++){
		logfile << " Status of " << elements[i] << " is ";	//Test messsage
		logfile << boolalpha << statistic[i] << " ";		//Status
		logfile << asctime(localtime(&result));				//Time of test
	}
	logfile.close();						//lose file after manipulations
}

////////////////////////////////////////////////////////////////////////
// Name:       Terminal::Terminal()
// Purpose:    Implementation of Terminal::Terminal()
// Comment:    !Standart constructor
// Return:     
////////////////////////////////////////////////////////////////////////

Terminal::Terminal()							 //!Default constructor
{
   Server = NULL;
#if (TEST == 1)
   cout << "'Terminal' - Standart constructor already started! " << endl;
#endif
}

////////////////////////////////////////////////////////////////////////
// Name:       Terminal::Terminal(Terminal& sTerminal)
// Purpose:    Implementation of Terminal::Terminal(Terminal& sTerminal)
// Comment:    !Constructor of copy
// Return:     
////////////////////////////////////////////////////////////////////////

Terminal::Terminal(const Terminal& sTerminal)			//!!Constructor of copy
	: m_Computer(sTerminal.m_Computer),
	  m_Printer (sTerminal.m_Printer),
	  m_Cashbox (sTerminal.m_Cashbox)
{
#if (TEST == 1)
	cout << "'Terminal' - Constructor of copy already started! " << endl;
#endif
}