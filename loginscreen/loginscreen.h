#ifndef LOGINSCREEN_H
# define LOGINSCREEN_H

# include <QtWidgets/QApplication>
# include <QtWidgets\QMainWindow>
# include <QtWidgets\qlineedit.h>
# include <QtWidgets\qboxlayout.h>
# include <QtWidgets\qlabel.h>
# include <QtCore\qstring.h>
# include <QtWidgets\qpushbutton.h>
# include "MainMenu.h"
# include "Hash.h"
#include "ParserXML.hh"


class LoginScreen : QObject
{
	Q_OBJECT
public:
	LoginScreen();
	~LoginScreen();
	void	show();

private:
	MainMenu	mainMenu;
	QString		log;
	QString		pass;
	QGridLayout	*layout;
	QWidget		*window;
	QLineEdit	*logField;
	QLineEdit	*pwdField;
	QLabel		*logLabel;
	QLabel		*pwdLabel;
	QPushButton	*connectButton;
	QPushButton	*signInButton;

private:
	void	initLabels();
	void	initFields();
	void	initButton();
	void	getInfo();

public slots:
	void	logIn();
	void	signIn();
};

#endif // LOGINSCREEN_H
