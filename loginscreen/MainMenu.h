#ifndef MAINMENU_H_
# define MAINMENU_H_
# include "APropos.h"
# include "ContactList.h"

class MainMenu : public QObject
{
	Q_OBJECT
public:
	MainMenu();
	~MainMenu();
	void	show();
	QMainWindow *getWindow();

private:
	void	initMenuBar();
private:
	QMainWindow	*window;
	QWidget		*mainWidget;
	QMenu		*menu;
	QAction		*add;
	QAction		*del;
	QAction		*aPropos;
	APropos		*info;
	ContactList	*list;
	QVBoxLayout	*contactLayout;

private slots:
	void	showAPropos();
};

#endif /* !MAINMENU_H_*/