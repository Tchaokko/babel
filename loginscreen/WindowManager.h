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
#include "confWindow.h"
#include "friendRequest.h"
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
	typedef struct		windowObject
	{
		ParserXML		parser;
		MainMenu		*_MainMenu;
		addWindow		*_addWindow;
		delWindow		*_delWindow;
		LoginScreen		*_loginScreen;
		IncCall			*_incCall;
		errorWindow		*_errorWindow;
		APropos			*_apropos;
		CallWindow		*_callWindow;
		confWindow		*_confWindow;
		friendRequest	*_friendRequest;
	}					wObject;

private:
	std::vector<void(*)(wObject&) >	checkMenuFunction;
	std::vector<void(*)(wObject &, char*) >	processFunction;
private:

	HandleSocket			*socketHandler;
	Protocol::RequestData	Request;
private:
	
	Hash			_hash;
	wObject			windowsObject;
	QLineEdit		_checkSocket;
	QLineEdit		_checkConfWindow;
	QLineEdit		_checkProtocol;
	QLineEdit		_checkCallWindow;
	QLineEdit		_checkMainMenu;
	QLineEdit		_checkIncomingCallWindow;
	QLineEdit		_checkLoginScreen;
	QLineEdit		_checkAddWindow;
	QLineEdit		_checkDelWindow;
	QLineEdit		_checkFriendRequest;

private:

	State		managerState;
	State		_state;
	void		setState(State );
	State		getState();

private:
	static	void	connectDone(wObject &, char *);
	static	void	connectDenied(wObject &, char *);
	static	void	disconnectIncoming(wObject &, char *);
	static	void	callIncoming(wObject &, char *);
	static	void	declinedCall(wObject &, char *);
	static	void	askContact(wObject &, char *);
	static	void	acceptedContact(wObject &, char *);
	static	void	refusedContact(wObject &, char *);

	void			connectServ(Protocol::Spef, QString &name, QString &Pass, QString &Ip);
	void			signIn(Protocol::Spef, QString &name, QString &Pass, QString &Ip);
	void			disconnectSend(Protocol::Spef, QString&);
	void			call(QString &);
	void			takeCall(QString&);
	void			declineCall(QString &);
	void			addContact(QString &);
	void			acceptContact(QString &);
	void			refuseContact(QString &);
	void			deleteContact(QString &);

	virtual bool	processRequest();


private:
	static void		menuAddContact(wObject &);
	static void		menuDelContact(wObject &);
	static void		menuCallContact(wObject &);
	static void		menuAPropos(wObject &);

private slots:
	void			checkCallWindow();
	void			checkIncomingCallWindow();
	void			checkMainMenu();
	void			checkLoginScreen();
	void			checkAddWindow();
	void			checkDelWindow();
	void			checkProtocol();
	void			checkConfWindow();
	void			checkSocket();
	void			checkFriendRequestWindow();
};

