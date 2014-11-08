#ifndef LOGINSCREEN_H
# define LOGINSCREEN_H

# include "IGraphique.h"
# include "Hash.h"

class LoginScreen : public IGraphique
{
	Q_OBJECT
public:
	LoginScreen(QLineEdit &action);
	virtual					 ~LoginScreen();
	virtual void			show();
	virtual QString const	&getInfo();
	QString const			&getInfo2();
	QString const			&getInfo3();
	void					closeLoginScreen();

private:
	QLineEdit				&action;

private:
	virtual void			setStyleSheet();

private slots:
	void					sendSignIn();
	void					sendConnexionRequest();
};


#endif // LOGINSCREEN_H
