#include "APropos.h"

void	APropos::show()
{
	this->windowAPropos->show();
}

void	APropos::setStyleSheet()
{
	this->windowAPropos->setStyleSheet("background-color: #00CED1");
}

APropos::APropos()
{
	this->windowAPropos= new QWidget(NULL);
	this->layout = new QVBoxLayout;
	this->version = new QLabel("v 1.0\n");
	this->login = new QLabel("Lebars_r\nrouber_l\nfirmin_v\ncombel_a\n");
	this->who = new QLabel("Par COMFIROLE");

	layout->addWidget(version);
	layout->addWidget(login);
	layout->addWidget(who);
	windowAPropos->setLayout(layout);
	this->setStyleSheet();
}

APropos::~APropos()
{
}
