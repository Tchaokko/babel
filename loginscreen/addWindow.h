#pragma once
#include "IGraphique.h"

class addWindow : public IGraphique
{
public:
	addWindow(QString &);
	virtual ~addWindow();
	virtual void	show();
	virtual	void	getInfo();
private:
	virtual	void	setStyleSheet();
	QString	&addFriend;
};

