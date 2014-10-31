#include "loginscreen.h"
#include "Hash.h"
#include "iostream"

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	LoginScreen	logScreen;
	Hash		toto;
	int			result;

	result = toto.hashing("");
	std::cout << "Test  " << result << std::endl;
	logScreen.show();
	return a.exec();
}
