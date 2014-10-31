#ifndef MAINMENU_H_
# define MAINMENU_H_
# include <QtWidgets\QApplication>
# include <QtWidgets\QMainWindow>
# include <qmenubar.h>
# include <qstring.h>

class MainMenu
{
public:
	MainMenu();
	~MainMenu();
	void	show();
	QMainWindow *getWindow();

private:
	void	initMenuBar();
private:
	QMainWindow	*window;
	QMenu		*menu;
	QAction		*add;
	QAction		*del;
};

#endif /* !MAINMENU_H_*/