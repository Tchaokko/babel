#include "WindowManager.h"

void	WindowManager::connectDone(wObject &_windowsObject)
{

}

void	WindowManager::connectDenied(wObject &_windowsObject)
{

}

void	WindowManager::disconnectIncoming(wObject &_windowsObject)
{

}

void	WindowManager::callIncoming(wObject &_windowsObject)
{
	/*_windowsObject._incCall->setLabel();     ADD LABEL RECEIVED BY TCP*/
	_windowsObject._incCall->show();
}

void	WindowManager::declinedCall(wObject &_windowsObject)
{

}

void	WindowManager::askContact(wObject &_windowsObject)
{

}

void	WindowManager::acceptedContact(wObject &_windowsObject)
{

}

void	WindowManager::refusedContact(wObject &_windowsObject)
{

}

void	WindowManager::connectServ(Protocol::Spef Type, uint32_t Dest)
{

}

void	WindowManager::signIn(Protocol::Spef Type, uint32_t Dest)
{

}

void	WindowManager::call(Protocol::Spef Type, uint32_t Dest)
{

}

void	WindowManager::takeCall(Protocol::Spef Type, uint32_t Dest)
{

}

void	WindowManager::declineCall(Protocol::Spef Type, uint32_t Dest)
{

}

void	WindowManager::addContact(Protocol::Spef Type, uint32_t Dest)
{

}

void	WindowManager::acceptContact(Protocol::Spef Type, uint32_t Dest)
{

}

void	WindowManager::refuseContact(Protocol::Spef Type, uint32_t Dest)
{

}

bool	WindowManager::processRequest(InternalProtocol::SpefSock Spef)
{

	for (int count = 0; count < 8; count++)
	{
		if (Spef == count)
			processFunction[count](this->windowsObject);
	}

	return true;
}

void			WindowManager::checkLoginScreen()
{

	QString temp = this->checkLoginScreen.text();
	QString name;

	if (temp.toInt() == InternalProtocol::SpefLogin::LOG_IN)
	{
		/*close Login screen*/
		this->windowsObject._MainMenu->show();
		name = this->windowsObject._loginScreen->getInfo();
		this->windowsObject._MainMenu->setUserName(name);
		this->windowsObject._MainMenu->initContactList();
	}
}

void			WindowManager::checkIncomningCallWindow()
{
	QString	temp = this->checkIncomingCallWindow.text();
	if (temp.toInt() == InternalProtocol::SpefIncCallWin::ACCEPT_CALL)
	{
		/*tell serv and pop confWindow*/
	}
	else if (temp.toInt() == InternalProtocol::SpefIncCallWin::DENY_CALL)
	{
		/* tell serv*/
	}
}

void			WindowManager::checkMainMenu()
{
	QString	temp = this->checkMainMenu.text();
	
	for (int count = 1; count < 3; count++)
	{
		if (temp.toInt() == count)
			this->checkMenuFunction[count](this->windowsObject);
	}
}

void			WindowManager::checkAddWindow()
{
	QString		temp = this->checkAddWindow.text();
	QString		name;

	if (temp.toInt() == InternalProtocol::SpefAddWin::ADD_CONTACT)
	{
		name = this->windowsObject._addWindow->getInfo();
		/*ask server*/
	}
}

void			WindowManager::checkDelWindow()
{
	QString		temp = this->checkDelWindow.text();
	QString		name;

	if (temp.toInt() == InternalProtocol::SpefDelWin::DEL_CONTACT)
	{
		name = this->windowsObject._delWindow->getInfo();
		/*ask serv*/
	}
}

void			WindowManager::checkCallWindow()
{
	QString temp = this->checkCallWindow.text();

	if (temp.toInt() == InternalProtocol::SpefCallWin::CALL_CONTACT)
	{
		this->windowsObject._MainMenu->getInfo();

	}
}

void			WindowManager::menuAddContact(wObject &windowsObject)
{
	windowsObject._addWindow->show();
}

void			WindowManager::menuDelContact(wObject &windowsObject)
{
	windowsObject._delWindow->show();
}

void			WindowManager::menuCallContact(wObject &windowObject)
{

}

void			WindowManager::setState(WindowManager::State type)
{
	this->managerState = type;
}

WindowManager::State			WindowManager::getState()
{

}

WindowManager::WindowManager()
{
	checkMenuFunction.push_back(WindowManager::menuAddContact);
	checkMenuFunction.push_back(WindowManager::menuDelContact);
	checkMenuFunction.push_back(WindowManager::menuCallContact);

	this->windowsObject._addWindow = new addWindow(this->checkAddWindow);
	this->windowsObject._delWindow = new delWindow(this->checkDelWindow);
	this->windowsObject._loginScreen = new LoginScreen(this->checkLoginScreen);
	this->windowsObject._MainMenu = new MainMenu(this->checkMainMenu);
	this->windowsObject._incCall = new MainMenu(this->checkIncomningCallWindow);

	connect(&this->checkProtocol, SIGNAL(textChanged(const QString &)), this, SLOT(checkProtocol()));
	connect(&this->checkAddWindow, SIGNAL(textChanged(const QString &)), this, SLOT(checkAddWindow()));
	connect(&this->checkMainMenu, SIGNAL(textChanged(const QString &)), this, SLOT(checkMainMenu()));
	connect(&this->checkIncomingCallWindow, SIGNAL(textChanged(const QString &)), this, SLOT(checkIncomingCallWindow()));
	connect(&this->checkLoginScreen, SIGNAL(textChanged(const QString &)), this, SLOT(checkLoginScreen()));
	connect(&this->checkAddWindow, SIGNAL(textChanged(const QString &)), this, SLOT(checkAddWindow()));
	connect(&this->checkDelWindow, SIGNAL(textChanged(const QString &)), this, SLOT(checkDelWindow()));
}




WindowManager::~WindowManager()
{
}
