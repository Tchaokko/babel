#include "MainMenu.h"

void	MainMenu::getInfo()
{

}

void	MainMenu::setStyleSheet()
{
	this->mainWidget->setStyleSheet("background-color: #00CED1");

}

void	MainMenu::setUserName(QString const &userName)
{
	this->userName = userName;
}

void	MainMenu::show()
{
	this->window->show();
}

QMainWindow	*MainMenu::getWindow()
{
	return this->window;
}

void	MainMenu::initContactList()
{
	this->list->initFriendList(this->userName);
}

void	MainMenu::initMenuBar()
{
	this->menu = this->window->menuBar()->addMenu("Contact");
	this->add = new QAction("&Add", this->window);
	this->del = new QAction("&Delete", this->window);
	this->menu->addAction(this->add);
	this->menu->addAction(this->del);
	this->menu = this->window->menuBar()->addMenu("?");
	this->aPropos = new QAction("A propos", this->window);
	this->menu->addAction(this->aPropos);
}

MainMenu::MainMenu()
{
	this->window = new QMainWindow(NULL);
	this->window->setWindowTitle("Comfirole");
	this->mainWidget = new QWidget(this->window);
	this->info = new APropos;

	this->list = new ContactList(&this->contactLayout);
	this->mainWidget->setLayout(&this->contactLayout);
	this->window->setCentralWidget(this->mainWidget);
	this->initMenuBar();
	this->setStyleSheet();
}

MainMenu::~MainMenu()
{
	delete this->add;
	delete this->del;
	delete this->aPropos;
	delete this->info;
	delete this->list;
}
