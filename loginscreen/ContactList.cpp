#include "ContactList.h"

void	ContactList::addWindowFunc()
{
	this->addWindow.show();
}

void	ContactList::addElem()
{
	this->data << this->addField.text();
	this->model.setStringList(this->data);
	this->addField.clear();
	this->addWindow.close();
}

ContactList::ContactList(QVBoxLayout *layout)
{
	this->layout = layout;
	this->view.setModel(&this->model);
	this->view.setEditTriggers(0);
	layout->addWidget(&this->view);

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
