#include "loginscreen.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	loginscreen w;
	w.show();
	return a.exec();
}
