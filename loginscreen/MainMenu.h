#ifndef MAINMENU_H_
# define MAINMENU_H_
# include "IGraphique.h"
# include "ParserXML.hh"
class MainMenu : public IGraphique
{
public:
	MainMenu();
	virtual ~MainMenu();
	virtual void	show();
	virtual	void	getInfo();
	void			setUserName(QString const &);
	void			initContactList();
	void			addElem(QString const &);
	void			delElem(QString const &);
private:
	void			initMenuBar();
	virtual void	setStyleSheet();
private:
	QString		userName;
	QMainWindow	*window;
	QMenu		*menu;
	QAction		*add;
	QAction		*del;
	QAction		*aPropos;
	ParserXML	parser;
	QListWidget	list;

};

#endif /* !MAINMENU_H_*/