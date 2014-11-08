#pragma once
#include "IGraphique.h"

class IncCall : public IGraphique
{
	Q_OBJECT
public:
	IncCall(QLineEdit &);
	virtual ~IncCall();
	virtual void show();
	virtual QString const	&getInfo();
	void					setLabel(QString &);
private:
	virtual void			setStyleSheet();
private:
	QLineEdit				&action;
private slots:
	void					deny();
	void					accept();
};

