/***********************************************************************
 * Module:  Cashbox.h
 * Author:  Roman Kaporin
 * Modified: 01 October 2014 20:35:17
 * Purpose: Declaration of the class Cashbox
 * Comment: !It's object that controls manipulation with money (collecting, saving, extracting)
 ***********************************************************************/

#if !defined(__Terminal_class_Cashbox_h)
#define __Terminal_class_Cashbox_h

#include "define.h"

class Cashbox
{
public:
   /**Adding money to Cashbox (it's check total value before adding money) */
   bool cashAdd(float);
   /**Showing money in Cashbox now */
   float getCashNow(void);
   /**Showing maximum value of money in Cashbox  */
   float getCashMax(void);
  
   friend class Engineer;

   Cashbox();						 //!Standart constructor
   Cashbox(float now, float max);	 //!Initialization constructor

protected:
private:
   /**Maximum that can get Cashbox from users */
   float cashMax;
   /**Total value of cash in Cashbox right now */
   float cashNow;
};

#endif