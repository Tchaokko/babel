#include "WindowManager.h"

void	WindowManager::connectDone(wObject &windowsObject, char *name)
{
	QString	_name;

	windowsObject._loginScreen->closeLoginScreen();
	windowsObject._MainMenu->show();
	_name = windowsObject._loginScreen->getInfo();
	windowsObject._MainMenu->setUserName(name);
	windowsObject._MainMenu->initContactList();

}

void	WindowManager::connectDenied(wObject &_windowsObject, char *name)
{
	QString	error("Connect Denied");

	_windowsObject._errorWindow->setLabel(error);
	_windowsObject._errorWindow->show();
}

void	WindowManager::disconnectIncoming(wObject &_windowsObject, char *name)
{
	QString	error("Disconnected");

	_windowsObject._errorWindow->setLabel(error);
	_windowsObject._errorWindow->show();
}

void	WindowManager::callIncoming(wObject &_windowsObject, char *name)
{
	QString		temp(name);

	_windowsObject._incCall->setLabel(temp);
	_windowsObject._incCall->show();
}

void	WindowManager::declinedCall(wObject &_windowsObject, char *name)
{
	_windowsObject._confWindow->closeConfW();
}

void	WindowManager::askContact(wObject &_windowsObject, char *name)
{
	_windowsObject._friendRequest->show();
}

void	WindowManager::acceptedContact(wObject &_windowsObject, char *name)
{
	_windowsObject._MainMenu->addElem(name);
}

void	WindowManager::refusedContact(wObject &_windowsObject, char *name)
{
	_windowsObject._errorWindow->setLabel(name);
	_windowsObject._errorWindow->setLabel2("Doest not want to be friend with you");
	_windowsObject._errorWindow->show();

}


void	WindowManager::connectServ(Protocol::Spef Type, QString &name, QString &Pass, QString &Ip)
{
	Protocol::RequestData		test;
	std::string					interm_name = name.toStdString();
	char						*interm_char;
	int							count = 0;
	int							hashed;
	while (count < 20)
	{
		test.Source[count] = interm_name.c_str()[count];
		count++;
	}
	test.Pwd = this->_hash.hashing(Pass.toStdString().c_str());
	test.Spef = Type;
	//this->socketHandler->connectToServ(test, ip);
}

void	WindowManager::FillRequest(Protocol::Spef type, QString &name)
{
	Protocol::RequestData		test;
	int							count = 0;


	while (count < 20)
	{
		test.Dest[count] = name.toStdString().c_str()[count];
		test.Source[count] = this->windowsObject._MainMenu->getUserName().toStdString().c_str()[count];
		count++;
	}
	test.Spef = type;
	//this->socketHandler->request(test, name);
}

void	WindowManager::checkSocket()
{
	QString	temp = this->_checkSocket.text();

	if (temp.toInt() == InternalProtocol::SpefSock::INC_REQUEST)
	{
		this->Request = this->socketHandler->getRequest();
		processRequest();
	}

}

bool	WindowManager::processRequest()
{

	for (int count = 0; count < 9; count++)
	{
		if (this->Request.Spef == count)
			processFunction[count](this->windowsObject, this->Request.Source);
	}

	return true;
}

void			WindowManager::checkLoginScreen()
{

	QString temp = this->_checkLoginScreen.text();
	QString login = this->windowsObject._loginScreen->getInfo();
	QString pass = this->windowsObject._loginScreen->getInfo2();
	QString	ip = this->windowsObject._loginScreen->getInfo3();

	if (temp.toInt() == InternalProtocol::SpefLogin::LOG_IN)
		this->connectServ(Protocol::CONNECT_REQUEST, login, pass, ip);
	else if (temp.toInt() == InternalProtocol::SpefLogin::SIGN_IN)
		this->connectServ(Protocol::SIGN_IN, login, pass, ip);
	this->windowsObject._loginScreen->resetAction();
}

void			WindowManager::checkIncomingCallWindow()
{
	QString	temp = this->_checkIncomingCallWindow.text();
	QString name;

	name = this->windowsObject._incCall->getInfo();
	if (temp.toInt() == InternalProtocol::SpefIncCallWin::ACCEPT_CALL)
	{
		this->FillRequest(Protocol::TAKE_CALL, name);
		this->windowsObject._incCall->show();
	}
	else if (temp.toInt() == InternalProtocol::SpefIncCallWin::DENY_CALL)
		this->FillRequest(Protocol::DECLINE_CALL, name);
	this->windowsObject._incCall->resetAction();
}

void			WindowManager::checkMainMenu()
{
	QString	temp = this->_checkMainMenu.text();
	
	for (int count = 1; count <= 4; count++)
	{
		if (temp.toInt() == count)
			this->checkMenuFunction[count - 1](this->windowsObject);
	}
}

void			WindowManager::checkAddWindow()
{
	QString		temp = this->_checkAddWindow.text();
	QString		name;

	if (temp.toInt() == InternalProtocol::SpefAddWin::ADD_CONTACT)
	{
		name = this->windowsObject._addWindow->getInfo();
		this->FillRequest(Protocol::ADD_CONTACT, name);
		this->windowsObject._addWindow->resetAction();
	}
}

void			WindowManager::checkDelWindow()
{
	QString		temp = this->_checkDelWindow.text();
	QString		name;

	if (temp.toInt() == InternalProtocol::SpefDelWin::DEL_CONTACT)
	{
		name = this->windowsObject._delWindow->getInfo();
		this->FillRequest(Protocol::DELETE_CONTACT, name);
		this->windowsObject._addWindow->resetAction();
	}
}

/* Check if you want to call in the window*/
void			WindowManager::checkCallWindow()
{
	QString temp = this->_checkCallWindow.text();
	QString name;

	if (temp.toInt() == InternalProtocol::SpefCallWin::CALL_CONTACT)
	{
		name = this->windowsObject._callWindow->getInfo();
		this->FillRequest(Protocol::CALL_CONTACT, name);
	}
}

void			WindowManager::menuAddContact(wObject &windowsObject)
{
	windowsObject._addWindow->show();
	windowsObject._MainMenu->resetAction();
}

void			WindowManager::menuDelContact(wObject &windowsObject)
{
	windowsObject._delWindow->show();
	windowsObject._MainMenu->resetAction();
}


/*Spawn the callWindow*/
void			WindowManager::menuCallContact(wObject &windowObject)
{
	QString	name;

	name = windowObject._MainMenu->getInfo();
	windowObject._callWindow->setLabel(name);
	windowObject._callWindow->show();
	windowObject._MainMenu->resetAction();
}

void			WindowManager::menuAPropos(wObject &windowObject)
{
	windowObject._apropos->show();
	windowObject._MainMenu->resetAction();
}

void			WindowManager::setState(WindowManager::State type)
{
	this->managerState = type;
}


WindowManager::State			WindowManager::getState()
{
	return this->_state;
}

void			WindowManager::checkConfWindow()
{
	QString		temp = this->_checkConfWindow.text();
	QString		name;

	if (temp.toInt() == InternalProtocol::ConfWin::HANGOUT)
	{
		name = this->windowsObject._confWindow->getInfo();
		this->FillRequest(Protocol::HANGOUT, name);
	}
}

void			WindowManager::checkFriendRequestWindow()
{
	QString		temp = this->_checkAddWindow.text();
	QString		name;

	if (temp.toInt() == InternalProtocol::SpeficifationFriendRequest::ACCEPT_F_REQUEST)
	{
		name = this->windowsObject._friendRequest->getInfo();
		this->FillRequest(Protocol::ACCEPT_CONTACT, name);
	}
	else if (temp.toInt() == InternalProtocol::SpeficifationFriendRequest::DENY_F_REQUEST)
	{
		name = this->windowsObject._friendRequest->getInfo();
		this->FillRequest(Protocol::REFUSE_CONTACT, name);
	}
	this->windowsObject._friendRequest->resetAction();
}

WindowManager::WindowManager()
{
	checkMenuFunction.push_back(WindowManager::menuAddContact);
	checkMenuFunction.push_back(WindowManager::menuDelContact);
	checkMenuFunction.push_back(WindowManager::menuCallContact);
	checkMenuFunction.push_back(WindowManager::menuAPropos);

	this->socketHandler = new HandleSocket(this->_checkSocket);
	this->windowsObject._addWindow = new addWindow(this->_checkAddWindow);
	this->windowsObject._delWindow = new delWindow(this->_checkDelWindow);
	this->windowsObject._callWindow = new CallWindow(this->_checkCallWindow);
	this->windowsObject._loginScreen = new LoginScreen(this->_checkLoginScreen);
	this->windowsObject._MainMenu = new MainMenu(this->_checkMainMenu);
	this->windowsObject._incCall = new IncCall(this->_checkIncomingCallWindow);
	this->windowsObject._confWindow = new confWindow(this->_checkConfWindow);
	this->windowsObject._apropos = new APropos;
	this->windowsObject._errorWindow = new errorWindow;
	this->windowsObject._friendRequest = new friendRequest(this->_checkFriendRequest);
	
	this->windowsObject._loginScreen->show();
	this->socketHandler->initSocketTcp("127.0.0.1");
	this->socketHandler->writeOnTcp();
	connect(&this->_checkAddWindow, SIGNAL(textChanged(const QString &)), this, SLOT(checkAddWindow()));
	connect(&this->_checkDelWindow, SIGNAL(textChanged(const QString &)), this, SLOT(checkDelWindow()));
	connect(&this->_checkMainMenu, SIGNAL(textChanged(const QString &)), this, SLOT(checkMainMenu()));
	connect(&this->_checkIncomingCallWindow, SIGNAL(textChanged(const QString &)), this, SLOT(checkIncomingCallWindow()));
	connect(&this->_checkLoginScreen, SIGNAL(textChanged(const QString &)), this, SLOT(checkLoginScreen()));
	connect(&this->_checkConfWindow, SIGNAL(textChanged(const QString &)), this, SLOT(checkConfWindow()));
	connect(&this->_checkFriendRequest, SIGNAL(textChanged(const QString &)), this, SLOT(checkFriendRequestWindow()));
	connect(&this->_checkSocket, SIGNAL(textChanged(const QString &)), this, SLOT(checkSocket()));
}

WindowManager::~WindowManager()
{
}
