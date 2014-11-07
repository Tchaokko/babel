#ifndef LOGINSCREEN_H
# define LOGINSCREEN_H

# include <QtWidgets/QApplication>
# include <QtWidgets/QMainWindow>
# include <QtWidgets/qlineedit.h>
# include <QtWidgets/qboxlayout.h>
# include <QtWidgets/qlabel.h>
# include <QtCore/qstring.h>
# include <QtWidgets/qpushbutton.h>
# include "IGraphique.h"
# include "Protocol.h"
# include "HandleProtocol.h"
# include "HandleSocket.h"
# include "MainMenu.h"
# include "Hash.h"
# include "ParserXML.hh"


class LoginScreen : public IGraphique
{
private:
	Q_OBJECT;
public:
	LoginScreen();
	virtual ~LoginScreen();
	virtual void	show();
	virtual void	getInfo();
private:
	MainMenu	mainMenu;
	Hash		_hash;
	QString		log;
	QString		pass;
	QGridLayout	*layout;
	QWidget		*window;
	QLineEdit	*logField;
	QLineEdit	*pwdField;
	QLineEdit	*ipField;
	QLabel		*logLabel;
	QLabel		*pwdLabel;
	QLabel		*ipLabel;
	QPushButton	*connectButton;
	QPushButton	*signInButton;

private:
	virtual void	setStyleSheet();
};


#endif // LOGINSCREEN_H
