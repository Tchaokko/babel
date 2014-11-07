#pragma once
#include "IGraphique.h"

class addWindow : public IGraphique
{
public:
	addWindow();
	virtual ~addWindow();
	virtual void	show();
	virtual	void	getInfo();
private:
	virtual	void	setStyleSheet();
};

