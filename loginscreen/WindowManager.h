#pragma once
#include <qlineedit.h>
#include <IGraphique.h>
#include "InternalProtocol.h"
#include "ContactList.h"
#include "MainMenu.h"
#include "CallWindow.h"
#include "loginscreen.h"
#include <vector>

class WindowManager : public QObject
{

	Q_OBJECT

public:
	WindowManager();
	~WindowManager();

private:
	std::vector<void(*)() >	checkMenuFunction;

private:
	QLineEdit		checkCallWindow;
	QLineEdit		checkMainMenu;
	QLineEdit		checkIncomingCallWindow;
	QLineEdit		checkLoginScreen;
	QLineEdit		checkAddWindow;
	QLineEdit		checkDelWindow;

private:
	static void		menuAddContact();
	static void		menuDelContact();
	static void		menuCallContact();

private slots:
	void			checkCallWindow();
	void			checkIncomningCallWindow();
	void			checkMainMenu();
	void			checkLoginScreen();
	void			checkAddWindow();
	void			checkDelWindow();
};

