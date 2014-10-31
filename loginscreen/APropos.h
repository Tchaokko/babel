#pragma once
# include <QtWidgets\QApplication>
# include <QtWidgets\QMainWindow>
# include <qmenubar.h>
# include <qstring.h>
# include <qlayout.h>
# include <QtWidgets\qlabel.h>

class APropos
{
public:
	APropos();
	~APropos();
	void	show();

private:
	QWidget		*windowAPropos;
	QVBoxLayout	*layout;
	QLabel		*version;
	QLabel		*login;
	QLabel		*who;
};

