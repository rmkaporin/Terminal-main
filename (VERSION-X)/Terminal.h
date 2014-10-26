/***********************************************************************
 * Module:  Terminal.h
 * Author:  Roman Kaporin
 * Modified: 01 October 2014 20:41:18
 * Purpose: Declaration of the class Terminal
 * Comment: !This class is main for modelling of terminal. It consist of three parts: Computer, Cashbox and Printer.
 ***********************************************************************/

#if !defined(__Terminal_class_Terminal_h)
#define __Terminal_class_Terminal_h
#define NULL 0

class Engineer;
class Server;

#include "Engineer.h"
#include "Computer.h"
#include "Cashbox.h"
#include "Printer.h"
#include "define.h"

class Terminal
{
public:
   /**Downloaded start configuration of system status at starting */
   void systemCheck(void);
   /**Sending statistic of work to Engineer*/
   bool* sendStatistic();

   Terminal();					  //!Standart constructor
   Terminal(const Terminal&); //!Constructor of copy

   Server** Server;		//Pointer to object Server
   friend class Engineer;

protected:
private:
	   /**Component of TERMINAL - obj. Computer */
   Computer m_Computer;
   /**Component of TERMINAL - obj. Cashbox */
   Cashbox m_Cashbox;
   /**Component of TERMINAL - obj. Printer */
   Printer m_Printer;
   /**Automatic picked up statistic about status of terminal*/ 
};

#endif