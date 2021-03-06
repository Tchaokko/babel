#include "CallWindow.h"

QString const	CallWindow::getInfo()
{
	return this->label1->text();
}

void		CallWindow::resetAction()
{
	this->action.clear();
}

void		CallWindow::setStyleSheet()
{
	this->widget->setStyleSheet("background-color: #00CED1");
	this->button1->setStyleSheet("background-color: #4eea58");
}

void	CallWindow::setLabel(QString &name)
{
	this->label1->setText(name);
}

void	CallWindow::show()
{
	this->widget->show();
}

void	CallWindow::call()
{
	int		nb = InternalProtocol::CALL_CONTACT;
	std::stringstream	stream;
	stream << nb;
	std::string			str(stream.str());
	QString				proto(str.c_str());

	this->action.setText(proto);
	this->widget->close();
}

CallWindow::CallWindow(QLineEdit &action) : action(action)
{
	this->widget = new QWidget(NULL);
	this->layout = new QGridLayout();
	this->button1 = new QPushButton("Call");
	this->label1 = new QLabel;
	this->label2 = new QLabel;
	this->layout->addWidget(this->label1, 0, 0);
	this->layout->addWidget(this->button1, 1, 0);
	this->widget->setLayout(this->layout);
	this->setStyleSheet();
	connect(this->button1, SIGNAL(clicked()), this, SLOT(call()));
}

CallWindow::~CallWindow()
{
	delete this->button1;
	delete this->label1;
}