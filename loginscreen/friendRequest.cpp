#include "friendRequest.h"

void	friendRequest::resetAction()
{
	this->action.clear();
}

void	friendRequest::acceptRequest()
{
	this->widget->close();
	int		nb = InternalProtocol::ACCEPT_F_REQUEST;
	std::stringstream	stream;
	stream << nb;
	std::string			str(stream.str());
	QString				proto(str.c_str());

	this->action.setText(proto);
}

void	friendRequest::denyRequest()
{
	this->widget->close();
	int		nb = InternalProtocol::DENY_F_REQUEST;
	std::stringstream	stream;
	stream << nb;
	std::string			str(stream.str());
	QString				proto(str.c_str());

	this->action.setText(proto);
}

QString const	friendRequest::getInfo()
{
	return (this->label2->text());
}

void	friendRequest::setStyleSheet()
{
	this->widget->setStyleSheet("background-color: #00CED1");
	this->button1->setStyleSheet("background-color: #4eea58");
	this->button2->setStyleSheet("background-color: #ea6d4e");
}

void	friendRequest::show()
{
	this->widget->show();
}

void	friendRequest::setLabel(QString const &userName)
{
	this->label2->setText(userName);
}

friendRequest::friendRequest(QLineEdit &action) : action(action)
{
	this->widget = new QWidget(NULL);
	this->layout = new QGridLayout;
	this->label1 = new QLabel("You receve a friend request from :");
	this->label2 = new QLabel;
	this->button1 = new QPushButton("Accept");
	this->button2 = new QPushButton("Deny");
	this->layout->addWidget(this->label1, 0, 0);
	this->layout->addWidget(this->label2, 1, 0);
	this->layout->addWidget(this->button1, 2, 0);
	this->layout->addWidget(this->button2, 2, 1);
	this->widget->setLayout(this->layout);
	this->setStyleSheet();
	connect(this->button1, SIGNAL(clicked()), this, SLOT(acceptRequest()));
	connect(this->button2, SIGNAL(clicked()), this, SLOT(denyRequest()));
}


friendRequest::~friendRequest()
{
	delete this->label1;
	delete this->label2;
	delete this->button1;
	delete this->button2;
}
