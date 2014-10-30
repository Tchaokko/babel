#ifndef  FIELDS_H_
# define	 FIELDS_H_
# include <QtWidgets\qlineedit.h>

class Fields
{
public:
	Fields();
	~Fields();

private:
	QLineEdit *login;
	QLineEdit *pass;

};

Fields::Fields()
{
}

Fields::~Fields()
{
}

#endif