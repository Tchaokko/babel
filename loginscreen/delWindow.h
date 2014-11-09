#pragma once
#include "IGraphique.h"
class delWindow : public IGraphique
{
	Q_OBJECT
public:
							delWindow(QLineEdit &);
	virtual					~delWindow();
	virtual void			show();
	virtual	QString const	getInfo();
	void					resetAction();
private:
	virtual	void			setStyleSheet();
private:
	QLineEdit				&action;
private slots:
	void			sendDelFriendRequest();
};

