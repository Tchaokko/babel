#include "WindowManager.h"

void	WindowManager::connectDone()
{

}

void	WindowManager::connectDenied()
{

}

void	WindowManager::disconnectIncoming()
{

}

void	WindowManager::callIncoming()
{

}

void	WindowManager::declinedCall()
{

}

void	WindowManager::askContact()
{

}

void	WindowManager::acceptedContact()
{

}

void	WindowManager::refusedContact()
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
			processFunction[count]();
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
		this->windowsObject._MainMenu.show();
		name = this->windowsObject._loginScreen.getInfo();
		this->windowsObject._MainMenu.setUserName(name);
		this->windowsObject._MainMenu.initContactList();
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
		/*close callwindow and tell serv*/
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
		name = this->windowsObject._addWindow.getInfo();
		/*ask server*/
	}
}

void			WindowManager::checkDelWindow()
{
	QString		temp = this->checkDelWindow.text();
	QString		name;

	if (temp.toInt() == InternalProtocol::SpefDelWin::DEL_CONTACT)
	{
		name = this->windowsObject._delWindow.getInfo();
		/*ask serv*/
	}
}

void			WindowManager::checkCallWindow()
{
	QString temp = this->checkCallWindow.text();

	if (temp.toInt() == InternalProtocol::SpefCallWin::CALL_CONTACT)
	{

	}
}

void			WindowManager::menuAddContact(wObject &windowsObject)
{
	windowsObject._addWindow.show();
}

void			WindowManager::menuDelContact(wObject &windowsObject)
{
	windowsObject._delWindow.show();
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
