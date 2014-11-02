#include "CallWindow.h"

CallWindow::CallWindow()
{
	this->window = new QWidget(NULL);
	this->layout = new QGridLayout();
	this->callButton = new QPushButton("Call");
	this->denyButton = new QPushButton("Deny");
	this->window->setLayout(this->layout);
	this->window->show();
}


CallWindow::~CallWindow()
{
}
