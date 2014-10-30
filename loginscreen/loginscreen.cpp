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
	QObject::connect(this->connectButton, SIGNAL(clicked()), this, SLOT(getInfo()));
}

void	LoginScreen::initButton()
{
	this->connectButton = new QPushButton("Connexion");
	this->signInButton = new QPushButton("Sign in");
}

void	LoginScreen::getInfo()
{
	this->pass = this->pwdField->text();
	this->log = this->logField->text();
	std::cout << log.toStdString() << std::endl;
	std::cout << "check" << std::endl;
	std::cout << pass.toStdString() << std::endl;
	std::cout << "check2" << std::endl;

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
