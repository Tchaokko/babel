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

ContactList::ContactList(QVBoxLayout *layout)
{
	this->layout = layout;
	layout->addWidget(&this->wlist);


	this->setStyleSheet();
	this->show();////////////////////////
	this->show2();///////////////////////
}


ContactList::~ContactList()
{
}
