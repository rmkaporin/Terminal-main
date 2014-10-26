/***********************************************************************
 * Module:  Computer.h
 * Author:  Roman Kaporin
 * Modified: 01 October 2014 20:36:29
 * Purpose: Declaration of the class Computer
 ***********************************************************************/

#include "define.h"

#if !defined(__Terminal_class_Computer_h)
#define __Terminal_class_Computer_h

class Engineer;
class Terminal;

class Computer
{
public:
   Computer();														//!Standart constructor
   Computer(bool dspl, bool cpu, bool mbrd, bool hdd, bool net);	//!Constructor with initialization
   bool BIOS();														//!Automatic checking Computer 

   friend class Engineer;

protected:
private:
   /**Creating account for user in current session */
   void userAcc(void);
   /**User input ticket information for requesting the Server */
   void userInput(void);
   /**Applying form for registration ticket */
   void userID(void);
   /**Receiving information from Server about ticket for user */
   void receivingRegStart(void);
   /**Registration ticket on Server */
   void receivingRegEnd(void);										    

   /**Showing status  terminal's display (true - OK, false - BAD) */
   bool display;
   /**Showing status  terminal's CPU (true - OK, false - BAD) */
   bool cpu;
   /**Showing status  terminal's motherboard (true - OK, false - BAD) */
   bool motherboard;
   /**Showing status  terminal's hdd (true - OK, false - BAD) */
   bool hdd;
   /**Showing status  terminal's network adapter (true - OK, false - BAD) */
   bool netAdapter;
};

#endif