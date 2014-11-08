#include "APropos.h"

void	APropos::closeAPropos()
{
	this->widget->close();
}

QString const	&APropos::getInfo()
{}

void	APropos::show()
{
	this->widget->show();
}

void	APropos::setStyleSheet()
{
	this->widget->setStyleSheet("background-color: #00CED1");
}

APropos::APropos()
{
	this->widget = new QWidget(NULL);
	this->layout = new QGridLayout;
	this->label1 = new QLabel("v 1.0\n");
	this->label2 = new QLabel("Lebars_r\nrouber_l\nfirmin_v\ncombel_a\n");
	this->label3 = new QLabel("Par COMFIROLE");
	this->button1 = new QPushButton("Ok");

	this->layout->addWidget(this->label1, 0, 0);
	this->layout->addWidget(this->label2, 1, 0);
	this->layout->addWidget(this->label3, 2, 0);
	this->layout->addWidget(this->button1, 3, 0);
	this->widget->setLayout(layout);
	this->setStyleSheet();
	connect(this->button1, SIGNAL(clicked()), this, SLOT(closeAPropos()));
}

APropos::~APropos()
{
	delete this->label1;
	delete this->label2;
	delete this->label3;
	delete this->button1;
}
