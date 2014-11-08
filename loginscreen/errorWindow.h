#pragma once
#include "IGraphique.h"
class				errorWindow : public IGraphique
{
	Q_OBJECT
public:
							errorWindow(QLineEdit &);
	virtual					~errorWindow();
	virtual QString const	&getInfo();
	virtual void			show();
	virtual void			setLabel(QString const &);
private:
	virtual void			setStyleSheet();
private:
	QLineEdit				&action;
private slots:
void						closeError();
};

