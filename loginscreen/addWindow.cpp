#include "addWindow.h"

void	addWindow::sendAddFriendRequest()
{
	/*Changer le QLineEdit*/
}

QString const	&addWindow::getInfo()
{
	return (this->field1->text());
}
void	addWindow::setStyleSheet()
{
	this->widget->setStyleSheet("background-color: #00CED1;");
	this->button1->setStyleSheet("background-color: #66e1e3");
	this->field1->setStyleSheet("background-color: #FFFFFF;");
}

void	addWindow::show()
{
	this->widget->show();
}

addWindow::addWindow(QLineEdit &action) : action(action)
{
	this->widget = new QWidget(NULL);
	this->widget->setWindowTitle("Add contact");
	this->layout = new QGridLayout;
	this->label1 = new QLabel("Login of the target :");
	this->field1 = new QLineEdit;
	this->button1 = new QPushButton("Add");
	this->layout->addWidget(this->label1, 0, 0);
	this->layout->addWidget(this->field1, 0, 1);
	this->layout->addWidget(this->button1, 2, 0, 2, 0);
	this->widget->setLayout(this->layout);
	connect(this->button1, SIGNAL(clicked()), this, SLOT(sendAddFriendRequest()));
}

addWindow::~addWindow()
{
	delete this->field1;
	delete this->label1;
	delete this->button1;
}
