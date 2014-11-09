#ifndef MAINMENU_H_
# define MAINMENU_H_
# include "IGraphique.h"
# include "ParserXML.hh"

class MainMenu : public IGraphique
{
	Q_OBJECT
public:
							MainMenu(QLineEdit &);
	virtual					~MainMenu();
	virtual void			show();
	virtual	QString const	getInfo();
	QString					&getUserName();
	void					setUserName(QString const &);
	void					initContactList();
	void					addElem(QString const &);
	void					delElem(QString const &);
	void					resetAction();
private:
	void					initMenuBar();
	virtual void			setStyleSheet();
private:
	QLineEdit				&action;
	QString					selection;
	QString					userName;
	QMainWindow				*window;
	QMenu					*menu;
	QAction					*add;
	QAction					*del;
	QAction					*aPropos;
	ParserXML				parser;
	QListWidget				list;
private slots:
	void					doubleClick(QListWidgetItem *);
	void					showAddWindow();
	void					showDelWindow();
	void					showApropos();

};

#endif /* !MAINMENU_H_*/