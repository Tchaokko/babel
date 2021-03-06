#include "errorWindow.h"

QString const	errorWindow::getInfo()
{
	return 0;
}

void	errorWindow::setLabel(QString const &warning)
{
	this->label1->setText(warning);
}

void	errorWindow::setStyleSheet()
{
	this->widget->setStyleSheet("background-color: #e74922");
	this->button1->setStyleSheet("background-color: #ea6d4e");
}

void	errorWindow::closeError()
{
	this->widget->close();
}

void	errorWindow::show()
{
	this->widget->show();
}
void	errorWindow::setLabel2(QString const &warning)
{
	this->label2->setText(warning);
}

errorWindow::errorWindow()
{
	this->widget = new QWidget(NULL);
	this->layout = new QGridLayout;
	this->label1 = new QLabel;
	this->label2 = new QLabel;
	this->button1 = new QPushButton("Ok");
	this->layout->addWidget(this->label1, 0, 0);
	this->layout->addWidget(this->label2, 1, 0);
	this->layout->addWidget(this->button1, 2, 0);
	this->widget->setLayout(this->layout);
	this->setStyleSheet();
	connect(this->button1, SIGNAL(clicked()), this, SLOT(closeError()));
}


errorWindow::~errorWindow()
{
	delete this->label1;
	delete this->label2;
	delete this->button1;
}
