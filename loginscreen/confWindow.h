#pragma once
#include					"IGraphique.h"
class						confWindow :
							public IGraphique
{
	Q_OBJECT

public:
							confWindow(QLineEdit &);
	virtual					~confWindow();
	virtual void			show();
	virtual QString const	getInfo();
	void					setLabel(QString &);
private:
	virtual void			setStyleSheet();
	QLineEdit				&action;
private slots:
	void					hangout();
};

