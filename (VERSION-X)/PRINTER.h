/***********************************************************************
 * Module:  Printer.h
 * Author:  Roman Kaporin
 * Modified: 01 October 2014 20:37:15
 * Purpose: Declaration of the class Printer
 ***********************************************************************/

#include "define.h"

#if !defined(__Terminal_class_Printer_h)
#define __Terminal_class_Printer_h

class Engineer;

class Printer
{
public:
   bool printTicket(void);  //!Printig tickets and bills after ticket's registration(check ability of printing before printing)
   bool selfCheck();		//!Looking for problems with Printer
   
   friend class Engineer;

   Printer();						//!Standart constructor
   Printer(int paper, float ink);   //!Constructor of initialization

protected:
private:
	/**Total value of ink in cartridge */
   float statusOfInk;
   /**Number lists of paper in Printer */
   int statusOfPaper;
};

#endif