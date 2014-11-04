#include "loginscreen.h"

void	LoginScreen::show()
{
	this->layout->addWidget(this->logLabel, 0, 0);
	this->layout->addWidget(this->logField, 0, 1);
	this->layout->addWidget(this->pwdLabel, 1, 0);
	this->layout->addWidget(this->pwdField, 1, 1);
	this->layout->addWidget(this->connectButton, 2, 0, 2, 0);
	this->layout->addWidget(this->signInButton, 4, 0, 2, 0);
	QObject::connect(this->signInButton, SIGNAL(clicked()), this, SLOT(signIn()));
//	QObject::connect(this->connectButton, SIGNAL(clicked()), this, SLOT(SendConnexionRequestToServer()));
//	QObject::connect(this->logField, SIGNAL(returnPressed()), this, SLOT(SendConnexionRequestToServer()));
//	QObject::connect(this->pwdField, SIGNAL(returnPressed()), this, SLOT(SendConnexionRequestToServer()));
	QObject::connect(this->connectButton, SIGNAL(clicked()), this, SLOT(logIn()));
	QObject::connect(this->logField, SIGNAL(returnPressed()), this, SLOT(logIn()));
	QObject::connect(this->pwdField, SIGNAL(returnPressed()), this, SLOT(logIn()));
}

void	LoginScreen::initButton()
{
	this->connectButton = new QPushButton("Connect");
	this->signInButton = new QPushButton("Sign in");
}

void	LoginScreen::signIn()
{
}

void	LoginScreen::SendConnexionRequestToServer()
{

}

void	LoginScreen::logIn()
{
	ParserXML	parser;

	this->window->close();
	this->getInfo();
	this->mainMenu.setUserName(this->log);
	this->mainMenu.initContactList();
	parser.createUser(this->log.toStdString());
	this->mainMenu.show();
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
	this->window = new QWidget(NULL);
	this->layout = new QGridLayout();
	this->initLabels();
	this->initFields();
	this->initButton();
	this->window->setLayout(this->layout);
	this->window->show();

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
	delete this->window;
}
