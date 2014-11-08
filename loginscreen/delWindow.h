#pragma once
#include "IGraphique.h"
class delWindow : public IGraphique
{
public:
	delWindow(QString &);
	virtual ~delWindow();
	virtual void	show();
	virtual	void	getInfo();
private:
	virtual	void	setStyleSheet();
private:
	QString	&delFriend;
};

