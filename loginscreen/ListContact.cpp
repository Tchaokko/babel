#include <qlistwidget.h>
#include <QtWidgets\qmainwindow.h>
#include <QtWidgets\qapplication.h>
#include "ListContact.h"
#include "qlayout.h"

ListContact::ListContact(QMainWindow *window)
{
	QListWidget *listWidget = new QListWidget(window);

	
	new QListWidgetItem(("Oak"), listWidget);
	new QListWidgetItem(("fire"), listWidget);
	new QListWidgetItem(("test"), listWidget);
}

ListContact::~ListContact()
{
}