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
#include "HandleProtocol.h"

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

protected slots:

	void	signIn();
	void	sendConnexionRequest();
	void	call();
	void	deny();
	void	accept();
	void	doubleClick(QListWidgetItem *);
	void	showAddWindow();
	void	showDelWindow();
	void	sendAddFriendRequest();
	void	sendDelFriendRequest();
	void	sendRequestToServer();
	void	showAPropos();
};

