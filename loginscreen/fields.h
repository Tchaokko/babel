#ifndef FIELDS_H_
# define FIELDS_H_
# include <QtWidgets\qlineedit.h>
# include <QtWidgets\qboxlayout.h>

class Field
{
public:
	Field(int = 0);
	~Field();
	void		show(QGridLayout *, int, int);

private:
	QLineEdit	*f;
};

void	Field::show(QGridLayout *layout, int x, int y)
{
	layout->addWidget(this->f, x, y);
}

Field::Field(int mode)
{
	if (mode == 0)
		this->f = new QLineEdit(NULL);
	else
	{
		this->f = new QLineEdit(NULL);
		this->f->setEchoMode(QLineEdit::Password);
	}
}

Field::~Field()
{
	delete this->f;
}

#endif