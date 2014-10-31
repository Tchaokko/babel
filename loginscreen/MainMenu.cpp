#include "MainMenu.h"

void	MainMenu::showAPropos()
{
	this->info->show();
}
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
	this->info = new APropos;
	this->menu = this->window->menuBar()->addMenu("Contact");
	this->add = new QAction("&Add", this->window);
	this->del = new QAction("&Delete", this->window);
	this->menu->addAction(this->add);
	this->menu->addAction(this->del);
	this->menu = this->window->menuBar()->addMenu("?");
	this->aPropos = new QAction("A propos", this->window);
	this->menu->addAction(this->aPropos);
	connect(this->aPropos, SIGNAL(triggered()), this, SLOT(showAPropos()));
}

MainMenu::MainMenu()
{
	this->window = new QMainWindow(NULL);
	this->initMenuBar();
}

MainMenu::~MainMenu()
{
}
