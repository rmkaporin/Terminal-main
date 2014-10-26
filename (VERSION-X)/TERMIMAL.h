/***********************************************************************
 * Module:  TERMIMAL.h
 * Author:  Roman Kaporin
 * Modified: 01 October 2014 20:41:18
 * Purpose: Declaration of the class TERMIMAL
 * Comment: !This class is main for modelling of terminal. It consist of three parts: computer, cashbox and printer.
 ***********************************************************************/

#if !defined(__Terminal_class_TERMIMAL_h)
#define __Terminal_class_TERMIMAL_h
#define NULL 0

class INGENIER;
class SERVER;

#include "INGENIER.h"
#include "COMPUTER.h"
#include "CASHBOX.h"
#include "PRINTER.h"

class TERMIMAL
{
public:
   /**Downloaded start configuration of system status at starting */
   void systemCheck(void);
   /**Sending statistic of work to ingenier*/
   bool* sendStatistic();

   TERMIMAL();					  //!Standart constructor
   TERMIMAL(const TERMIMAL&); //!Constructor of copy

   SERVER** sERVER;		//Pointer to object server
   friend class INGENIER;

protected:
private:
	   /**Component of TERMINAL - obj. Computer */
   COMPUTER m_computer;
   /**Component of TERMINAL - obj. Cashbox */
   CASHBOX m_cashbox;
   /**Component of TERMINAL - obj. Printer */
   PRINTER m_printer;
   /**Automatic picked up statistic about status of terminal*/ 
};

#endif