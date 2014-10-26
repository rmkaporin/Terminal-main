/***********************************************************************
 * Module:  Cashbox.cpp
 * Author:  Roman Kaporin
 * Modified: 01 October 2014 20:35:17
 * Purpose: Implementation of the class Cashbox
 * Comment: !It's object that controls manipulation with money (collecting, saving, extracting)
 ***********************************************************************/
#include <iostream>
#include <fstream>
using namespace std;

#include "Cashbox.h"

////////////////////////////////////////////////////////////////////////
// Name:       Cashbox::cashAdd()
// Purpose:    Implementation of Cashbox::cashAdd()
// Comment:    !Adding money to Cashbox (it's check total value before adding money)
// Return:     bool
////////////////////////////////////////////////////////////////////////

bool Cashbox::cashAdd(float addMoney)
{
	if ((cashNow >= cashMax) || (addMoney > (cashMax - cashNow)))
	//If Cashbox overloaded or here is not enough free space for add to much money
		return false;	//Say - unpossible to add money
	else cashNow += addMoney;
		return true;	//Else add money, and say that all is OK
}

////////////////////////////////////////////////////////////////////////
// Name:       Cashbox::getCashNow()
// Purpose:    Implementation of Cashbox::getCashNow()
// Comment:    !Showing money in Cashbox now
// Return:     float
////////////////////////////////////////////////////////////////////////

float Cashbox::getCashNow(void)
{
   // TODO : implement
	return 0;
}

////////////////////////////////////////////////////////////////////////
// Name:       Cashbox::getCashMax()
// Purpose:    Implementation of Cashbox::getCashMax()
// Comment:    !Showing maximum value of money in Cashbox 
// Return:     float
////////////////////////////////////////////////////////////////////////

float Cashbox::getCashMax(void)
{
   // TODO : implement
	return 0;
}


////////////////////////////////////////////////////////////////////////
// Name:       Cashbox::Cashbox()
// Purpose:    Implementation of Cashbox::Cashbox()
// Comment:    !Standart constructor
// Return:     
////////////////////////////////////////////////////////////////////////

Cashbox::Cashbox()						//!Standart constructor
{
	ifstream conf ("CashboxC.txt");	//Open conf file of Printer

	if (conf.good()) {			//If we can read file, then
		char buf[10];				//Buffer for config data

		conf.getline(buf, 10);		//Get inf. about start status of ink
		cashNow = atof(buf);

		conf.getline(buf, 10);		//Get inf. about start status of paper
		cashMax = atof(buf); 

		conf.close();

		cout << "'Cashbox' - Standart constructor already started FROM FILE!" << endl;
	}
	else {						//If we can't, then 
		cashNow = 0;
		cashMax = 1000;
		cout << "'Cashbox' - Standart constructor already started FROM DEFAULT!" << endl;
	}
}

////////////////////////////////////////////////////////////////////////
// Name:       Cashbox::Cashbox(float now, float max)
// Purpose:    Implementation of Cashbox::Cashbox(float now, float max)
// Comment:    !Constructor with initialization
// Return:     
////////////////////////////////////////////////////////////////////////

Cashbox::Cashbox(float now, float max)	//!Constructor with initialization
	: cashNow(now),
	  cashMax(max)
{
	cout << "'Cashbox' - Constructor with initialization already started!" <<endl;
}