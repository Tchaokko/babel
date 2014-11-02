#include "loginscreen.h"
#include "MainMenu.h"
#include "Hash.h"
#include <iostream>


int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	LoginScreen	logScreen;
	MainMenu	mainMenu;
	Hash		toto;

	logScreen.show();
	mainMenu.show();
	return a.exec();
}
