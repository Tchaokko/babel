#ifndef IGRAPHIQUE
# define IGRAPHIQUE
# include "Babel.h"

class IGraphique : public Babel
{
public:
	virtual void	show() = 0;
	virtual void	getInfo() = 0;
protected:
	virtual void	setStyleSheet() = 0;
	QWidget			*widget;
	QGridLayout		*layout;
	QLineEdit		*field1;
	QLineEdit		*field2;
	QLineEdit		*field3;
	QLabel			*label1;
	QLabel			*label2;
	QLabel			*label3;
	QPushButton		*button1;
	QPushButton		*button2;
};

#endif /*IGRAPH*/