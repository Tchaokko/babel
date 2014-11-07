#include "CallWindow.h"

void		CallWindow::getInfo()
{

}

void		CallWindow::setStyleSheet()
{
	this->windowCall->setStyleSheet("background-color: #00CED1");
	this->windowIncoming->setStyleSheet("background-color: #00CED1");
	this->acceptButton->setStyleSheet("background-color: #4eea58");
	this->callButton->setStyleSheet("background-color: #4eea58");
	this->denyButton->setStyleSheet("background-color: #ea6d4e");
}

void	CallWindow::nameLabel(const QString &name)
{
	this->layoutCall->addWidget(this->callButton, 1, 0);
	this->layoutCall->addWidget(this->label, 0, 0);
	this->label->setText(name);
	this->windowCall->setLayout(this->layoutCall);
	this->windowCall->show();

}

void	CallWindow::show()
{
	this->windowIncoming->setLayout(this->layoutCall);
	this->windowIncoming->show();
}

void	CallWindow::callIncoming(const QString &name)
{
	this->label->setText(name);
	this->windowIncoming->setLayout(this->layoutIncoming);
	this->show();
}

CallWindow::CallWindow()
{
	this->windowCall = new QWidget(NULL);
	this->windowIncoming = new QWidget(NULL);
	this->layoutCall = new QGridLayout();
	this->layoutIncoming = new QGridLayout();
	this->callButton = new QPushButton("Call");
	this->denyButton = new QPushButton("Deny");
	this->acceptButton = new QPushButton("Accept");
	this->label = new QLabel();
	this->incoming = new QLabel("Incoming call from");
	this->layoutCall->addWidget(this->callButton, 1, 0);
	this->layoutCall->addWidget(this->label, 0, 0);
	this->layoutIncoming->addWidget(this->incoming, 0, 0);
	this->layoutIncoming->addWidget(this->acceptButton, 2, 0);
	this->layoutIncoming->addWidget(this->denyButton, 3, 0);
	this->layoutIncoming->addWidget(this->label, 1, 0);

	this->setStyleSheet();
	//this->show();
	this->callIncoming("toto");
}

CallWindow::~CallWindow()
{
}
