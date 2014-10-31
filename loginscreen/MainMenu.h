#ifndef MAINMENU_H_
# define MAINMENU_H_
# include "APropos.h"

class MainMenu : public QObject
{
	Q_OBJECT
public:
	MainMenu();
	~MainMenu();
	void	show();

private:
	void	initMenuBar();
private:
	QMainWindow	*window;
	QMenu		*menu;
	QAction		*add;
	QAction		*del;
	QAction		*aPropos;
	APropos		*info;

private slots:
	void	showAPropos();
};

#endif /* !MAINMENU_H_*/