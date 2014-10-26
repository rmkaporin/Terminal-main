/***********************************************************************
 * Module:  INGENIER.h
 * Author:  Roman Kaporin
 * Modified: 01 October 2014 20:35:17
 * Purpose: Declaration of the class INGENIER
 * Comment: !It's object that repear terminal
 ***********************************************************************/
#include "CASHBOX.h"
#include "COMPUTER.h"
#include "PRINTER.h"
#include "TERMIMAL.h"


#if !defined(__Terminal_class_INGENIER_h)
#define __Terminal_class_INGENIER_h

//class TERMIMAL;
//class PRINTER;
//class COMPUTER;
//class CASHBOX;

class INGENIER
{

public:
	INGENIER();
	void logAnalitic();					//Automatic analizing log of terminal

	void takeTerminalAdress(TERMIMAL *);


protected:
private:
	TERMIMAL *adressForSupport;		//Adress of terminal to repear
	float money;					//!Money, that ingenier picked up from cashbox
	void readAndFixComputer(char*);
	void readAndFixPrinter(char*);
	void readAndFixCashBox(char*);
};

#endif