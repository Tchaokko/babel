#include "loginscreen.h"
#include "MainMenu.h"
#include "Hash.h"


int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	LoginScreen	logScreen;
	MainMenu	mainMenu;
	int			result;

	result = toto.hashing("");
	std::cout << "Test  " << result << std::endl;
	logScreen.show();
	mainMenu.show();
	return a.exec();
}
