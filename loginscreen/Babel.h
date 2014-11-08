#pragma once

#include <qobject.h>
#include <qlistwidget.h>
#include <HandleSocket.h>
#include <HandleProtocol.h>
#include <InterfaceProtocol.h>
#include <QtWidgets\qlineedit.h>
#include <QtWidgets\qpushbutton.h>
#include <QtWidgets\qlabel.h>
#include <QtWidgets\qgridlayout.h>
#include <QtWidgets\qmenu.h>
#include <QtWidgets\qmenubar.h>

class Babel : public QObject 
{
private:
	Q_OBJECT;

public:
	Babel();
	~Babel();

private:
	
	HandleSocket	socketHandler;
	HandleProtocol	protocolHandler;

protected:
	QString			save1;
	QString			save2;
	QString			save3;

protected slots:

	void	signIn();
	void	sendConnexionRequest();
	void	call();
	void	deny();
	void	accept();
	void	doubleClick(QListWidgetItem *);
	void	ShowAddWindow();
	void	ShowDelWindow();
	void	sendAddFriendRequest();
	void	sendDelFriendRequest();
	void	sendRequestToServer();
	void	showAPropos();
};

