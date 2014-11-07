#pragma once

# include <QtWidgets/QApplication>
# include <QtWidgets/QMainWindow>
# include <QtWidgets/qlineedit.h>
# include <QtWidgets/qboxlayout.h>
# include <QtWidgets/qlabel.h>
# include <QtCore/qstring.h>
# include <QtWidgets/qpushbutton.h>
# include "IGraphique.h"

class CallWindow : public IGraphique
{

public:
	CallWindow();
	virtual ~CallWindow();
	void			nameLabel(const QString &);
	virtual	void	show();
	virtual void	getInfo();
	void			callIncoming(const QString &);

private:
	virtual void		setStyleSheet();
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
};

