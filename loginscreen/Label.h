#ifndef LABEL_H_
# define LABEL_H_
# include <string>
# include <QtWidgets\qlabel.h>
# include <QtCore\qstring.h>

class Label
{
public:
	Label(const std::string &);
	~Label();
	void	setMsg(std::string const &);
	void	show(QGridLayout *, int, int);
private:
	QLabel		*l;
};

void	Label::show(QGridLayout *layout, int x, int y)
{
	layout->addWidget(this->l, x, y);
}

void	Label::setMsg(std::string const &msg)
{
	QString		myMsg(msg.c_str());

	this->l->setText(myMsg);
}

Label::Label(std::string const &msg)
{
	this->l = new QLabel(msg.c_str());
}

Label::~Label()
{
	delete this->l;
}

#endif