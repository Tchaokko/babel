#include "loginscreen.h"
#include "MainMenu.h"
#include "Hash.h"
#include "ListContact.h"
#include <iostream>


int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	LoginScreen	logScreen;
	MainMenu	mainMenu;
	Hash		toto;
	QMainWindow	*window;

	logScreen.show();
	window = mainMenu.getWindow();
	ListContact test(window);
	mainMenu.show();
	return a.exec();
}
