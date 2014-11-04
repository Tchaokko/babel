#pragma once

# include <QtWidgets/QApplication>
# include <QtWidgets/QMainWindow>
# include <QtWidgets/qlineedit.h>
# include <QtWidgets/qboxlayout.h>
# include <QtWidgets/qlabel.h>
# include <QtCore/qstring.h>
# include <QtWidgets/qpushbutton.h>

class CallWindow : QObject
{

	Q_OBJECT
public:
	CallWindow();
	~CallWindow();
	void		nameLabel(const QString &);
	void		show();
	void		callIncoming(const QString &);

private:

	QLabel		*incoming;
	QPushButton *callButton;
	QPushButton *acceptButton;
	QWidget		*windowCall;
	QWidget		*windowIncoming;
	QPushButton *denyButton;
	QGridLayout *layoutCall;
	QGridLayout *layoutIncoming;
	QLabel		*label;

public slots:
	void	call();
	void	deny();
	void	accept();
};

