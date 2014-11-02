#include "ContactList.h"

void	ContactList::addWindowFunc()
{
	this->addWindow.show();
}

void	ContactList::addElem()
{
	this->wlist.addItem(this->addField.text());
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
	}
	this->delField.clear();
	this->delWindow.close();
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
