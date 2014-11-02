#ifndef CONTACTLIST_H_
# define CONTACTLIST_H_
# include <QtWidgets\qapplication.h>
# include <QtWidgets\qmainwindow.h>
# include <QtWidgets\qboxlayout.h>
# include <QtCore\qstringlistmodel.h>
# include <QtWidgets\qlistview.h>
# include <QtWidgets\qlistwidget.h>
# include <QtWidgets\qpushbutton.h>
# include <QtWidgets\qlabel.h>
# include <QtCore\qstring.h>
# include <QtWidgets\qlineedit.h>
# include <QModelIndex>
#include "CallWindow.h"

class ContactList : public QObject
{
	Q_OBJECT
public:
	ContactList(QVBoxLayout *);
	~ContactList();
private:
	QListWidget			wlist;
	QVBoxLayout			*layout;
	CallWindow			call;
private:
	QWidget				addWindow;
	QGridLayout			addLayout;
	QLabel				addLabel;
	QLineEdit			addField;
	QPushButton			addButton;

private slots:
	void	doubleClick(QListWidgetItem *);
	void	addWindowFunc();
	void	addElem();
};

#endif /*CONTACTLIST */