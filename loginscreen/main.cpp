#include "loginscreen.h"
#include "iostream"
int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	LoginScreen	logScreen;

	std::cout << "test" << std::endl;
	logScreen.show();
	return a.exec();
}
