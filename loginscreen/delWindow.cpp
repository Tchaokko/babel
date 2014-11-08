#include "delWindow.h"

void	delWindow::setStyleSheet()
{
	this->widget->setStyleSheet("background-color: #00CED1;");
	this->button1->setStyleSheet("background-color: #66e1e3");
	this->field1->setStyleSheet("background-color: #FFFFFF;");
}

void	delWindow::show()
{
	this->widget->show();
}

void	delWindow::getInfo()
{
	this->delFriend = this->field1->text();
}

delWindow::delWindow(QString &delFriend) : delFriend(delFriend)
{
	this->widget = new QWidget(NULL);
	this->widget->setWindowTitle("Del contact");
	this->layout = new QGridLayout;
	this->label1 = new QLabel("Login of the target :");
	this->field1 = new QLineEdit;
	this->button1 = new QPushButton("Del");
	this->layout->addWidget(this->label1, 0, 0);
	this->layout->addWidget(this->field1, 0, 1);
	this->layout->addWidget(this->button1, 2, 0, 2, 0);
	this->widget->setLayout(this->layout);
	connect(this->button1, SIGNAL(clicked()), this, SLOT(sendDelFriendRequest());
}


delWindow::~delWindow()
{
}
