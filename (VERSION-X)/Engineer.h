/***********************************************************************
 * Module:  Engineer.h
 * Author:  Roman Kaporin
 * Modified: 01 October 2014 20:35:17
 * Purpose: Declaration of the class Engineer
 * Comment: !It's object that repear terminal
 ***********************************************************************/
#include "Cashbox.h"
#include "Computer.h"
#include "Printer.h"
#include "Terminal.h"
#include "define.h"


#if !defined(__Terminal_class_Engineer_h)
#define __Terminal_class_Engineer_h

//class Terminal;
//class Printer;
//class Computer;
//class Cashbox;

class Engineer
{

public:
	Engineer();
	void logAnalitic();					//Automatic analizing log of terminal

	void takeTerminalAdress(Terminal *);


protected:
private:
	Terminal *adressForSupport;		//Adress of terminal to repear
	float money;					//!Money, that Engineer picked up from Cashbox
	void readAndFixComputer(char*,Computer&);
	void readAndFixPrinter(char*, Printer&);
	void readAndFixCashbox(char*, Cashbox&);
};

#endif