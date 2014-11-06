#include "loginscreen.h"


void	LoginScreen::setStyleSheet()
{
	this->window->setStyleSheet("background-color: #00CED1;");
	this->connectButton->setStyleSheet("background-color: #66e1e3;");
	this->signInButton->setStyleSheet("background-color: #66e1e3;");
	this->logLabel->setStyleSheet("background-color: rgba(0,0,0,0)");
	this->pwdLabel->setStyleSheet("background-color: rgba(0,0,0,0)");
	this->logField->setStyleSheet("background-color: rgba(255,255,255,255)");
	this->pwdField->setStyleSheet("background-color: rgba(255,255,255,255)");
	this->ipField->setStyleSheet("background-color: rgba(255,255,255,255)");
}

void	LoginScreen::show()
{
	this->window->show();
}

void	LoginScreen::getInfo()
{
	this->pass = this->pwdField->text();
	this->log = this->logField->text();
}

LoginScreen::LoginScreen()
{
	this->window = new QWidget(NULL);
	this->layout = new QGridLayout();
	this->connectButton = new QPushButton("Connect");
	this->signInButton = new QPushButton("Sign in");
	this->logLabel = new QLabel("Login: ");
	this->pwdLabel = new QLabel("Password:");
	this->logField = new QLineEdit(NULL);
	this->pwdField = new QLineEdit(NULL);
	this->pwdField->setEchoMode(QLineEdit::Password);
	this->ipField = new QLineEdit(NULL);
	this->ipLabel = new QLabel("Ip server:");
	this->window->setLayout(this->layout);
	this->layout->addWidget(this->logLabel, 0, 0);
	this->layout->addWidget(this->logField, 0, 1);
	this->layout->addWidget(this->pwdLabel, 1, 0);
	this->layout->addWidget(this->pwdField, 1, 1);
	this->layout->addWidget(this->ipLabel, 2, 0);
	this->layout->addWidget(this->ipField, 2, 1);
	this->layout->addWidget(this->connectButton, 3, 0, 2, 0);
	this->layout->addWidget(this->signInButton, 5, 0, 2, 0);
	this->setStyleSheet();
}

LoginScreen::~LoginScreen()
{
	delete this->logField;
	delete this->pwdField;
	delete this->ipField;
	delete this->logLabel;
	delete this->ipLabel;
	delete this->pwdLabel;
	delete this->layout;
	delete this->window;
}
