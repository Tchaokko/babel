#ifndef LOGINSCREEN_H
# define LOGINSCREEN_H

# include <QtWidgets/QApplication>
# include <QtWidgets\QMainWindow>
# include <QtWidgets\qlineedit.h>
# include <QtWidgets\qboxlayout.h>
# include <QtWidgets\qlabel.h>
# include <QtCore\qstring.h>
# include <QtWidgets\qpushbutton.h>

class LoginScreen : QObject
{
	Q_OBJECT
public:
	LoginScreen();
	~LoginScreen();
	void	show();

private:
	QString		log;
	QString		pass;
	QGridLayout	*layout;
	QWidget		*mainWidget;
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

public slots:
	void	getInfo();
};

#endif // LOGINSCREEN_H
