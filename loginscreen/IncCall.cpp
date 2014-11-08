#include "IncCall.h"

void	IncCall::setLabel(QString &name)
{
	this->label1->setText(name);
}

QString const	&IncCall::getInfo()
{
	return this->label1->text();
}

void	IncCall::setStyleSheet()
{
	this->widget->setStyleSheet("background-color: #00CED1");
	this->button1->setStyleSheet("background-color: #4eea58");
	this->button2->setStyleSheet("background-color: #ea6d4e");
}

void	IncCall::show()
{
	this->widget->show();
}

void	IncCall::deny()
{
	/*Change the QLineEdit*/
	this->widget->close();
}

void	IncCall::accept()
{
	/*Change the QLineEdit*/
	this->widget->close();
}

IncCall::IncCall(QLineEdit &action) : action(action)
{
	this->widget = new QWidget(NULL);
	this->layout = new QGridLayout;
	this->label1 = new QLabel;
	this->button1 = new QPushButton("Accept");
	this->button2 = new QPushButton("Deny");
	this->setStyleSheet();
	this->layout->addWidget(this->label1, 0, 0);
	this->layout->addWidget(this->button1, 1, 0);
	this->layout->addWidget(this->button1, 1, 1);
	this->widget->setLayout(this->layout);
	connect(this->button1, SIGNAL(clicked()), this, SLOT(accept()));
	connect(this->button2, SIGNAL(clicked()), this, SLOT(deny()));
}


IncCall::~IncCall()
{
	delete this->label1;
	delete this->button1;
	delete this->button2;
}
