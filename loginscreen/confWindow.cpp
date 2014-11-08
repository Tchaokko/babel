#include "confWindow.h"

void	confWindow::hangout()
{
	int		nb = InternalProtocol::HANGOUT;
	std::stringstream	stream;
	stream << nb;
	std::string			str(stream.str());
	QString				proto(str.c_str());

	this->action.setText(proto);
}

QString const	&confWindow::getInfo()
{}

void	confWindow::show()
{
	this->widget->show();
}

void	confWindow::setStyleSheet()
{
	this->widget->setStyleSheet("background-color: #4eea58");
	this->button2->setStyleSheet("background-color: #ea6d4e");
}

confWindow::confWindow(QLineEdit &action) : action(action)
{
	this->widget = new QWidget(NULL);
	this->layout = new QGridLayout;
	this->label1 = new QLabel;
	this->button1 = new QPushButton("hangout");
	this->layout->addWidget(this->label1, 0, 0);
	this->layout->addWidget(this->button1, 1, 0, 0, 3);
	this->setStyleSheet();
	connect(this->button1, SIGNAL(clicked()), this, SLOT(hangout()));
}


confWindow::~confWindow()
{
	delete this->label1;
	delete this->button1;
}
