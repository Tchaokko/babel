#ifndef LOGINSCREEN_H
#define LOGINSCREEN_H

#include <QtWidgets/QMainWindow>
#include "ui_loginscreen.h"

class loginscreen : public QMainWindow
{
	Q_OBJECT

public:
	loginscreen(QWidget *parent = 0);
	~loginscreen();

private:
	Ui::loginscreenClass ui;
};

#endif // LOGINSCREEN_H
