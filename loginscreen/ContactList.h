#ifndef CONTACTLIST_H_
# define CONTACTLIST_H_
# include <QtWidgets/qapplication.h>
# include <QtWidgets/qmainwindow.h>
# include <QtWidgets/qboxlayout.h>
# include <QtCore/qstringlistmodel.h>
# include <QtWidgets/qlistview.h>
# include <QtWidgets/qlistwidget.h>
# include <QtWidgets/qpushbutton.h>
# include <QtWidgets/qlabel.h>
# include <QtCore/qstring.h>
# include <QtWidgets/qlineedit.h>
# include <QModelIndex>
# include "IGraphique.h"
# include "CallWindow.h"
# include "ParserXML.hh"

class ContactList : public IGraphique
{
public:
	ContactList(QVBoxLayout *);
	virtual ~ContactList();
	virtual void	show();
	void			show2();
	virtual	void	getInfo();
	void			getInfo2();
private:
	virtual void		setStyleSheet();
	void				addElem(QString const &);
	void				delElem(QString const &);

private:
	QVBoxLayout			*layout;
	CallWindow			call;
};

#endif /*CONTACTLIST */