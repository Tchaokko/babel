#include "loginscreen.h"

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	LoginScreen	logScreen;
	logScreen.show();

	return a.exec();
}
