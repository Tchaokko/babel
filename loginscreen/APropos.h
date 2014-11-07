#ifndef APROPOS_H_
# define APROPOS_H_
# include <QtWidgets/QApplication>
# include <QtWidgets/QMainWindow>
# include <qmenubar.h>
# include <qstring.h>
# include <qlayout.h>
# include <QtWidgets/qlabel.h>
# include "IGraphique.h"

class APropos : public IGraphique
{
public:
	APropos();
	virtual ~APropos();
	virtual void	getInfo();
	virtual void	show();

private:
	virtual void	setStyleSheet();
private:
	QWidget		*windowAPropos;
	QVBoxLayout	*layout;
	QLabel		*version;
	QLabel		*login;
	QLabel		*who;
};

#endif /* APROPOS_H_*/