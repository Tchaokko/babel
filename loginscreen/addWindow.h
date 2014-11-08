#pragma once
#include "IGraphique.h"

class addWindow : public IGraphique
{
	Q_OBJECT
public:
	addWindow(QLineEdit &);
	virtual ~addWindow();
	virtual void	show();
	virtual	QString const &getInfo();
private:
	virtual	void	setStyleSheet();
private:
	QLineEdit	&action;
private slots:
	void			sendAddFriendRequest();
};

