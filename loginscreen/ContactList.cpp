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
	this->addField.clear();
	this->addWindow.close();
}

ContactList::ContactList(QVBoxLayout *layout)
{

	this->layout = layout;
	layout->addWidget(&this->wlist);
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
	connect(&this->addField, SIGNAL(returnPressed()), this, SLOT(addElem()));
}


ContactList::~ContactList()
{
}
