#include "MainMenu.h"

void	MainMenu::show()
{
	this->window->show();
}

QMainWindow *MainMenu::getWindow()
{
	return this->window;
}

void	MainMenu::initMenuBar()
{
	this->menu = this->window->menuBar()->addMenu("Contact");
	this->add = new QAction("&Add", this->window);
	this->del = new QAction("&Delete", this->window);
	this->menu->addAction(this->add);
	this->menu->addAction(this->del);
}

MainMenu::MainMenu()
{
	this->window = new QMainWindow(NULL);
	this->initMenuBar();
}

MainMenu::~MainMenu()
{
}
