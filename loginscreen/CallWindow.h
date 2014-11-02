#pragma once

# include <QtWidgets/QApplication>
# include <QtWidgets\QMainWindow>
# include <QtWidgets\qlineedit.h>
# include <QtWidgets\qboxlayout.h>
# include <QtWidgets\qlabel.h>
# include <QtCore\qstring.h>
# include <QtWidgets\qpushbutton.h>

class CallWindow
{
public:
	CallWindow();
	~CallWindow();

private:
	QPushButton *callButton;
	QWidget		*window;
	QPushButton *denyButton;
	QGridLayout *layout;
};

