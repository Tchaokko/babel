#ifndef MAINMENU_H_
# define MAINMENU_H_
# include "IGraphique.h"
# include "APropos.h"
# include "ContactList.h"

class MainMenu : public IGraphique
{
public:
	MainMenu();
	virtual ~MainMenu();
	virtual void	show();
	virtual	void	getInfo();
	QMainWindow		*getWindow();
	void			setUserName(QString const &);
	void			initContactList();
private:
	void			initMenuBar();
	virtual void	setStyleSheet();
private:
	QString		userName;
	QMainWindow	*window;
	QWidget		*mainWidget;
	QMenu		*menu;
	QAction		*add;
	QAction		*del;
	QAction		*aPropos;
	APropos		*info;
	ContactList	*list;
	QVBoxLayout	contactLayout;
};

#endif /* !MAINMENU_H_*/