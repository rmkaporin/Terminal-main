#include "Terminal.h"
#include "Server.h"
#include "Engineer.h"

#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <iostream>
using namespace std;

int main() {
	cout << "Standart constructors: " <<endl;

	Terminal Terminal;
	Server Server;
	Engineer Engineer;

	cout << endl << endl;

	Engineer.takeTerminalAdress(&Terminal);

	cout << "Test terminal before editing..." << endl;
	Terminal.systemCheck();
	Engineer.logAnalitic();
	cout << "Test terminal after editing..." << endl;
	Terminal.systemCheck();

	//cout << "Constuctor of copies: " << endl;
	//Terminal copyTerm(Terminal);
	//cout << endl << endl;

	//cout << "Constructor of initialization" << endl;
	//Computer Computer1(false, false, false, false, false);
	//Computer Computer;
	////Computer.BIOS();
	//Printer Printer1(10 , 100);

	system("pause");
	return 0;
}