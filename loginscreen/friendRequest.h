#pragma once
#include "IGraphique.h"

class friendRequest : public IGraphique
{
	Q_OBJECT
public:
	friendRequest(QLineEdit &);
	virtual ~friendRequest();
	virtual QString const	getInfo();
	virtual	void			show();
	void					setLabel(QString const &);
	void					resetAction();
private:
	virtual void			setStyleSheet();
private:
	QLineEdit				&action;
private slots:
void					acceptRequest();
void					denyRequest();
};

