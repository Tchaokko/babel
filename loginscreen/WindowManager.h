#pragma once
#include <qlineedit.h>
#include <IGraphique.h>
#include "InternalProtocol.h"
#include "MainMenu.h"
#include "CallWindow.h"
#include "addWindow.h"
#include "delWindow.h"
#include "loginscreen.h"
#include "IncCall.h"
#include "errorWindow.h"
#include "APropos.h"
#include "CallWindow.h"
#include <vector>

class WindowManager : public QObject
{

	Q_OBJECT

	typedef enum State
	{
		REST = 1,
		INCOMING_CALL,
		CALLING,
	}State;

public:
	WindowManager();
	~WindowManager();

private:
	typedef struct windowObject
	{
		MainMenu	*_MainMenu;
		addWindow	*_addWindow;
		delWindow	*_delWindow;
		LoginScreen	*_loginScreen;
		IncCall		*_incCall;
		errorWindow	*_errorWindow;
		APropos		*_apropos;
		CallWindow	*_callWindow;
	}wObject;

private:
	std::vector<void(*)(wObject&) >	checkMenuFunction;
	std::vector<void(*)(wObject &) >	processFunction;
private:

	HandleSocket	socketHandler;
	State			managerState;
	wObject			windowsObject;
	QLineEdit		_checkProtocol;
	QLineEdit		_checkCallWindow;
	QLineEdit		_checkMainMenu;
	QLineEdit		_checkIncomingCallWindow;
	QLineEdit		_checkLoginScreen;
	QLineEdit		_checkAddWindow;
	QLineEdit		_checkDelWindow;


private:
	State		_state;
	void		setState(State );
	State		getState();

private:
	static	void	connectDone(wObject &);
	static	void	connectDenied(wObject &);
	static	void	disconnectIncoming(wObject &);
	static	void	callIncoming(wObject &);
	static	void	declinedCall(wObject &);
	static	void	askContact(wObject &);
	static	void	acceptedContact(wObject &);
	static	void	refusedContact(wObject &);

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
	static void		menuAddContact(wObject &);
	static void		menuDelContact(wObject &);
	static void		menuCallContact(wObject &);

private slots:
	void			checkCallWindow();
	void			checkIncomningCallWindow();
	void			checkMainMenu();
	void			checkLoginScreen();
	void			checkAddWindow();
	void			checkDelWindow();
};

