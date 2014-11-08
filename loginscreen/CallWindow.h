#pragma once

# include					"IGraphique.h"

class						CallWindow : public IGraphique
{
							Q_OBJECT
public:
							CallWindow(QLineEdit &);
	virtual					~CallWindow();
	void					setLabel(QString &);
	virtual	void			show();
	virtual QString const	&getInfo();

private:
	virtual void			setStyleSheet();
private:
	QLineEdit				&action;
private slots:
void						call();
};

