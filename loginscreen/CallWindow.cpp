#include "CallWindow.h"

void	CallWindow::nameLabel(const QString &name)
{
	this->label->setText(name);
}

void	CallWindow::show()
{
	this->window->show();
}

void	CallWindow::call()
{
	
}

void	CallWindow::deny()
{

}

CallWindow::CallWindow()
{
	this->window = new QWidget(NULL);
	this->layout = new QGridLayout();
	this->callButton = new QPushButton("Call");
	this->denyButton = new QPushButton("Deny");
	this->label = new QLabel();
	this->layout->addWidget(this->callButton,1,0);
	this->layout->addWidget(this->denyButton,2,0);
	this->layout->addWidget(this->label,0,0);
	this->window->setLayout(this->layout);
	QObject::connect(this->callButton, SIGNAL(clicked()), this, SLOT(call()));
	QObject::connect(this->denyButton, SIGNAL(clicked()), this, SLOT(deny()));
}

CallWindow::~CallWindow()
{
}
