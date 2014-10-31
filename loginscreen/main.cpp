#include "loginscreen.h"
#include "MainMenu.h"

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	LoginScreen	logScreen;
	MainMenu	mainMenu;

	logScreen.show();
	mainMenu.show();
	return a.exec();
}
