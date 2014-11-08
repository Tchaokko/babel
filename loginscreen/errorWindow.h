#pragma once
#include "IGraphique.h"
class				errorWindow : public IGraphique
{
	Q_OBJECT
public:
							errorWindow();
	virtual					~errorWindow();
	virtual QString const	&getInfo();
	virtual void			show();
	virtual void			setLabel(QString const &);
private:
	virtual void			setStyleSheet();
private slots:
void						closeError();
};

