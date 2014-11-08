#include "errorWindow.h"

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

errorWindow::errorWindow(QLineEdit &action) : action(action)
{
	this->widget = new QWidget(NULL);
	this->layout = new QGridLayout;
	this->label1 = new QLabel;
	this->button1 = new QPushButton("Ok");
	this->layout->addWidget(this->label1, 0, 0);
	this->layout->addWidget(this->button1, 1, 0, 0, 4);
	this->setStyleSheet();
	connect(this->button1, SIGNAL(clicked()), this, SLOT(closeError()));
}


errorWindow::~errorWindow()
{
	delete this->label1;
	delete this->button1;
}
