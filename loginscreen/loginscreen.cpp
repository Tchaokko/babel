#include "loginscreen.h"

void		LoginScreen::closeLoginScreen()
{
	this->widget->close();
}

void	LoginScreen::setStyleSheet()
{
	this->widget->setStyleSheet("background-color: #00CED1;");
	this->button1->setStyleSheet("background-color: #66e1e3;");
	this->button2->setStyleSheet("background-color: #66e1e3;");
	this->label1->setStyleSheet("background-color: rgba(0,0,0,0)");
	this->label2->setStyleSheet("background-color: rgba(0,0,0,0)");
	this->field1->setStyleSheet("background-color: rgba(255,255,255,255)");
	this->field2->setStyleSheet("background-color: rgba(255,255,255,255)");
	this->field3->setStyleSheet("background-color: rgba(255,255,255,255)");
}

void	LoginScreen::show()
{
	this->widget->show();
}

QString	const	&LoginScreen::getInfo()
{
	return (this->field1->text());
}

QString	const	&LoginScreen::getInfo2()
{
	return (this->field2->text());
}

QString	const	&LoginScreen::getInfo3()
{
	return (this->field3->text());
}

void		LoginScreen::sendSignIn()
{
	int		nb = InternalProtocol::SIGN_IN;
	std::stringstream	stream;
	stream << nb;
	std::string			str(stream.str());
	QString				proto(str.c_str());

	this->action.setText(proto);
}

void		LoginScreen::sendConnexionRequest()
{
	int		nb = InternalProtocol::LOG_IN;
	std::stringstream	stream;
	stream << nb;
	std::string			str(stream.str());
	QString				proto(str.c_str());

	this->action.setText(proto);
}

LoginScreen::LoginScreen(QLineEdit &action) : action(action)
{
	this->widget = new QWidget(NULL);
	this->layout = new QGridLayout();
	this->button1 = new QPushButton("Connect");
	this->button2 = new QPushButton("Sign in");
	this->label1 = new QLabel("Login: ");
	this->label2 = new QLabel("Password:");
	this->field1 = new QLineEdit(NULL);
	this->field2 = new QLineEdit(NULL);
	this->field2->setEchoMode(QLineEdit::Password);
	this->field3 = new QLineEdit(NULL);
	this->label3 = new QLabel("Ip server:");
	this->widget->setLayout(this->layout);
	this->layout->addWidget(this->label1, 0, 0);
	this->layout->addWidget(this->field1, 0, 1);
	this->layout->addWidget(this->label2, 1, 0);
	this->layout->addWidget(this->field2, 1, 1);
	this->layout->addWidget(this->label3, 2, 0);
	this->layout->addWidget(this->field3, 2, 1);
	this->layout->addWidget(this->button1, 3, 0, 2, 0);
	this->layout->addWidget(this->button2, 5, 0, 2, 0);
	this->setStyleSheet();
	QObject::connect(this->button2, SIGNAL(clicked()), this, SLOT(signIn()));
	QObject::connect(this->button1, SIGNAL(clicked()), this, SLOT(sendConnexionRequestToServer()));
	QObject::connect(this->field1, SIGNAL(returnPressed()), this, SLOT(sendConnexionRequestToServer()));
	QObject::connect(this->field2, SIGNAL(returnPressed()), this, SLOT(sendConnexionRequestToServer()));
	QObject::connect(this->field3, SIGNAL(returnPressed()), this, SLOT(sendConnexionRequestToServer()));
}

LoginScreen::~LoginScreen()
{
	delete this->field1;
	delete this->field2;
	delete this->field3;
	delete this->label1;
	delete this->label2;
	delete this->label3;
	delete this->layout;
}
