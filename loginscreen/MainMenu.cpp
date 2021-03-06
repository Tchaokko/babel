#include "MainMenu.h"

QString const	MainMenu::getInfo()
{
	return (this->selection);
}

void	MainMenu::addElem(QString const &addField)
{
	this->list.addItem(addField);
	this->parser.addFriend(addField.toStdString(), this->userName.toStdString());
}

void	MainMenu::delElem(QString const &delField)
{
	QList<QListWidgetItem *>	listItem = this->list.findItems(delField, Qt::MatchCaseSensitive);
	QListWidgetItem				*item;
	int row;

	if (listItem.isEmpty() == false)
	{
		row = this->list.row(listItem.back());
		item = this->list.takeItem(row);
		this->list.removeItemWidget(item);
		this->parser.removeFriend(delField.toStdString(), this->userName.toStdString());
	}
}

void	MainMenu::setStyleSheet()
{
	this->widget->setStyleSheet("background-color: #00CED1");
	this->list.setStyleSheet("background-color: #FFFFFF;");
}

void	MainMenu::setUserName(QString const &userName)
{
	this->userName = userName;
}

void	MainMenu::show()
{
	this->window->show();
}

QString		&MainMenu::getUserName()
{
	return this->userName;
}

void	MainMenu::initContactList()
{
	std::list<std::string>				friendList;
	std::list<std::string>::iterator	it;
	QString								str;

	friendList = this->parser.listOfFriend(this->userName.toStdString());
	for (it = friendList.begin(); it != friendList.end(); it++)
	{
		str = (*it).c_str();
		this->list.addItem(str);
		str.clear();
	}

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

void		MainMenu::resetAction()
{
	this->action.clear();
}

void		MainMenu::doubleClick(QListWidgetItem *item)
{
	this->selection = item->text();
	int		nb = InternalProtocol::POP_CALL_CONTACT;
	std::stringstream	stream;
	stream << nb;
	std::string			str(stream.str());
	QString				proto(str.c_str());
	this->action.setText(proto);
}

void		MainMenu::showAddWindow()
{
	int		nb = InternalProtocol::POP_ADD_CONTACT;
	std::stringstream	stream;
	stream << nb;
	std::string			str(stream.str());
	QString				proto(str.c_str());

	this->action.setText(proto);
}

void		MainMenu::showDelWindow()
{
	int		nb = InternalProtocol::POP_DEL_CONTACT;
	std::stringstream	stream;
	stream << nb;
	std::string			str(stream.str());
	QString				proto(str.c_str());

	this->action.setText(proto);
}

void		MainMenu::showApropos()
{
	int		nb = InternalProtocol::POP_APROPOS;
	std::stringstream	stream;
	stream << nb;
	std::string			str(stream.str());
	QString				proto(str.c_str());

	this->action.setText(proto);
}


MainMenu::MainMenu(QLineEdit &action) : action(action)
{
	this->window = new QMainWindow(NULL);
	this->window->setWindowTitle("Comfirole");
	this->widget = new QWidget(this->window);
	this->layout = new QGridLayout;
	this->layout->addWidget(&this->list, 0, 0);
	this->widget->setLayout(this->layout);
	this->window->setCentralWidget(this->widget);
	this->initMenuBar();
	this->setStyleSheet();
	connect(&this->list, SIGNAL(itemDoubleClicked(QListWidgetItem *)), this, SLOT(doubleClick(QListWidgetItem *)));
	connect(this->add, SIGNAL(triggered()), this, SLOT(showAddWindow()));
	connect(this->del, SIGNAL(triggered()), this, SLOT(showDelWindow()));
	connect(this->aPropos, SIGNAL(triggered()), this, SLOT(showApropos()));
}

MainMenu::~MainMenu()
{
	delete this->add;
	delete this->del;
	delete this->aPropos;
}
