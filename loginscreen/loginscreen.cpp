#include "loginscreen.h"
#include "iostream"

void	LoginScreen::show()
{
	this->layout->addWidget(this->logLabel, 0, 0);
	this->layout->addWidget(this->logField, 0, 1);
	this->layout->addWidget(this->pwdLabel, 1, 0);
	this->layout->addWidget(this->pwdField, 1, 1);
	this->layout->addWidget(this->connectButton, 2, 0, 2, 0);
	this->layout->addWidget(this->signInButton, 4, 0, 2, 0);
	QObject::connect(this->connectButton, SIGNAL(clicked()), this, SLOT(logIn()));
}

void	LoginScreen::initButton()
{
	this->connectButton = new QPushButton("Connexion");
	this->signInButton = new QPushButton("Sign in");
}

void	LoginScreen::signIn()
{
}

void	LoginScreen::logIn()
{
	this->mainWidget->close();
	this->mainWidget = new QWidget(NULL);
	QVBoxLayout		*lay = new QVBoxLayout(this->mainWidget);
	QLabel			*PraticalJoke = new QLabel("Celui qui lit ca est un con");

	lay->addWidget(PraticalJoke);
	this->mainWidget->setLayout(lay);
	this->mainWidget->show();

}

void	LoginScreen::getInfo()
{
	this->pass = this->pwdField->text();
	this->log = this->logField->text();
}
void	LoginScreen::initLabels()
{
	this->logLabel = new QLabel("Login: ");
	this->pwdLabel = new QLabel("Password:");
}

void	LoginScreen::initFields()
{
	this->logField = new QLineEdit(NULL);
	this->pwdField = new QLineEdit(NULL);
	this->pwdField->setEchoMode(QLineEdit::Password);
}

LoginScreen::LoginScreen()
{
	this->mainWidget = new QWidget(NULL);
	this->layout = new QGridLayout();
	this->initLabels();
	this->initFields();
	this->initButton();
	this->mainWidget->setLayout(this->layout);
	this->mainWidget->show();

}

LoginScreen::~LoginScreen()
{
	delete this->logLabel;
	delete this->pwdLabel;
	delete this->logField;
	delete this->pwdField;
	delete this->connectButton;
	delete this->signInButton;
	delete this->layout;
	delete this->mainWidget;
}
