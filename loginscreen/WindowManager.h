#pragma once
#include <qlineedit.h>
#include <IGraphique.h>
#include "InternalProtocol.h"
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
	std::vector<void(*)() >	processFunction;

private:
	static	void	connectDone();
	static	void	connectDenied();
	static	void	disconnectIncoming();
	static	void	callIncoming();
	static	void	declinedCall();
	static	void	askContact();
	static	void	acceptedContact();
	static	void	refusedContact();

	static	void	connectServ(Protocol::Spef, uint32_t);
	static	void	disconnectSend(Protocol::Spef, uint32_t);
	static	void	signIn(Protocol::Spef, uint32_t);
	static	void	call(Protocol::Spef, uint32_t);
	static	void	takeCall(Protocol::Spef, uint32_t);
	static	void	declineCall(Protocol::Spef, uint32_t);
	static	void	addContact(Protocol::Spef, uint32_t);
	static	void	acceptContact(Protocol::Spef, uint32_t);
	static	void	refuseContact(Protocol::Spef, uint32_t);

	virtual bool	processRequest(InternalProtocol::SpefSock);
	virtual bool	sendRequest(Protocol::Spef, uint32_t);

private:

	HandleSocket	socketHandler;

	QLineEdit		checkProtocol;
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

