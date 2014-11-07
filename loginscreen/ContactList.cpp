#include "ContactList.h"
#include "CallWindow.h"

void		ContactList::show()
{
	this->addWindow.show();
}

void		ContactList::show2()
{
	this->delWindow.show();
}

void		ContactList::getInfo()
{

}
void		ContactList::getInfo2()
{

}

void		ContactList::setStyleSheet()
{
	this->wlist.setStyleSheet("background-color: #FFFFFF;");
	this->addWindow.setStyleSheet("background-color: #00CED1;");
	this->addButton.setStyleSheet("background-color: #66e1e3");
	this->addField.setStyleSheet("background-color: #FFFFFF;");
	this->delWindow.setStyleSheet("background-color: #00CED1;");
	this->delButton.setStyleSheet("background-color: #66e1e3");
	this->delField.setStyleSheet("background-color: #FFFFFF");
}


void	ContactList::addElem(QString const &addField)
{
	this->wlist.addItem(addField);
	this->parser.addFriend(addField.toStdString(), this->userName.toStdString());
}

void	ContactList::delElem(QString const &delField)
{
	QList<QListWidgetItem *>	listItem = this->wlist.findItems(delField, Qt::MatchCaseSensitive);
	QListWidgetItem *item;
	int row;

	if (listItem.isEmpty() == false)
	{
		row = this->wlist.row(listItem.back());
		item = this->wlist.takeItem(row);
		this->wlist.removeItemWidget(item);
		this->parser.removeFriend(delField.toStdString(), this->userName.toStdString());
	}
}

void		ContactList::initFriendList(QString &userName)
{
	std::list<std::string>				friendList;
	std::list<std::string>::iterator	it;
	QString								str;

	this->userName = userName;
	friendList = this->parser.listOfFriend(this->userName.toStdString());
	for (it = friendList.begin(); it != friendList.end(); it++)
	{
		str = (*it).c_str();
		this->wlist.addItem(str);
		str.clear();
	}
}

ContactList::ContactList(QVBoxLayout *layout)
{
	this->layout = layout;
	layout->addWidget(&this->wlist);

	this->addWindow.setWindowTitle("Add contact");
	this->addLabel.setText("Login of the target :");
	this->addButton.setText("Add");
	this->addLayout.addWidget(&this->addLabel, 0, 0);
	this->addLayout.addWidget(&this->addField, 0, 1);
	this->addLayout.addWidget(&this->addButton, 2, 0, 2, 0);
	this->addWindow.setLayout(&this->addLayout);

	this->delWindow.setWindowTitle("Delete contact");
	this->delLabel.setText("Login of the target :");
	this->delButton.setText("Delete");
	this->delLayout.addWidget(&this->delLabel, 0, 0);
	this->delLayout.addWidget(&this->delField, 0, 1);
	this->delLayout.addWidget(&this->delButton, 2, 0, 2, 0);
	this->delWindow.setLayout(&this->delLayout);

	this->setStyleSheet();
	this->show();////////////////////////
	this->show2();///////////////////////
}


ContactList::~ContactList()
{
}
