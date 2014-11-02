#pragma once

# include <QtWidgets/QApplication>
# include <QtWidgets\QMainWindow>
# include <QtWidgets\qlineedit.h>
# include <QtWidgets\qboxlayout.h>
# include <QtWidgets\qlabel.h>
# include <QtCore\qstring.h>
# include <QtWidgets\qpushbutton.h>

class CallWindow : QObject
{

	Q_OBJECT
public:
	CallWindow();
	~CallWindow();
	void		nameLabel(const QString &);
	void		show();

private:
	QPushButton *callButton;
	QWidget		*window;
	QPushButton *denyButton;
	QGridLayout *layout;
	QLabel		*label;

public slots:
	void	call();
	void	deny();
};

