#include "fields.h"
#include "Label.h"
#include <QtWidgets/QApplication>
#include <QtWidgets\qpushbutton.h>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	QWidget	*mainWidget = new QWidget(NULL);
	Field	login;
	Field	pass(1);
	Label	log("Login :");
	Label	pwd("Password :");
	QGridLayout	*layout = new QGridLayout;

	QPushButton *connexion = new QPushButton("Connexion");
	QPushButton *signIn = new QPushButton("Sign In");

	log.show(layout, 0, 0);
	login.show(layout, 0, 1);
	pwd.show(layout, 1, 0);
	pass.show(layout, 1, 1);

	layout->addWidget(connexion, 2, 0, 2, 0);
	layout->addWidget(signIn, 4, 0, 2, 0);

	mainWidget->setLayout(layout);
	mainWidget->show();
	return a.exec();
}
