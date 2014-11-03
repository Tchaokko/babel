#include "ContactList.h"
#include "CallWindow.h"

void	ContactList::doubleClick(QListWidgetItem *item)
{
	QString		label;

	label = item->text();
	this->call.nameLabel(label);
	this->call.show();
}

void	ContactList::addWindowFunc()
{
	this->addWindow.show();
}

void	ContactList::addElem()
{
	this->wlist.addItem(this->addField.text());
	this->parser.addFriend((this->addField.text()).toStdString(), this->userName.toStdString());
	this->addField.clear();
	this->addWindow.close();
}

void	ContactList::delWindowFunc()
{
	this->delWindow.show();
}

void	ContactList::delElem()
{
	QList<QListWidgetItem *>	listItem = this->wlist.findItems(this->delField.text(), Qt::MatchCaseSensitive);
	QListWidgetItem *item;
	int row;

	if (listItem.isEmpty() == false)
	{
		row = this->wlist.row(listItem.back());
		item = this->wlist.takeItem(row);
		this->wlist.removeItemWidget(item);
		this->parser.removeFriend((this->delField.text()).toStdString(), this->userName.toStdString());
	}
	this->delField.clear();
	this->delWindow.close();
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
		std::cout << str.toStdString() << std::endl;
		this->wlist.addItem(str);
		str.clear();
	}
}

ContactList::ContactList(QVBoxLayout *layout)
{
	this->layout = layout;
	str = "test";
	layout->addWidget(&this->wlist);
	this->call.callIncoming(str);
	this->call.show();
	connect(&this->wlist, SIGNAL(itemDoubleClicked(QListWidgetItem *)), this, SLOT(doubleClick(QListWidgetItem *)));

	this->addWindow.setWindowTitle("Add contact");
	this->addLabel.setText("Login of the target :");
	this->addButton.setText("Add");
	this->addLayout.addWidget(&this->addLabel, 0, 0);
	this->addLayout.addWidget(&this->addField, 0, 1);
	this->addLayout.addWidget(&this->addButton, 2, 0, 2, 0);
	this->addWindow.setLayout(&this->addLayout);
	connect(&this->addButton, SIGNAL(clicked()), this, SLOT(addElem()));
	connect(&this->addField, SIGNAL(returnPressed()), this, SLOT(addElem()));

	this->delWindow.setWindowTitle("Delete contact");
	this->delLabel.setText("Login of the target :");
	this->delButton.setText("Delete");
	this->delLayout.addWidget(&this->delLabel, 0, 0);
	this->delLayout.addWidget(&this->delField, 0, 1);
	this->delLayout.addWidget(&this->delButton, 2, 0, 2, 0);
	this->delWindow.setLayout(&this->delLayout);
	connect(&this->delButton, SIGNAL(clicked()), this, SLOT(delElem()));
	connect(&this->delField, SIGNAL(returnPressed()), this, SLOT(delElem()));

}


ContactList::~ContactList()
{
}
