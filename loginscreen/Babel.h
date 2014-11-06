#pragma once

#include <qobject.h>
#include <qlistwidget.h>
#include <HandleSocket.h>
#include <HandleProtocol.h>

class Babel : QObject 
{
public:
	Babel();
	~Babel();

private:
	
	HandleSocket	socketHandler;
	HandleProtocol	protocolHandler;

protected:
	QString			ip;
	QString			Pwd;
	QString			Log;

protected slots:

	void	signIn();
	void	sendConnexionRequestToServer();
	void	call();
	void	deny();
	void	accept();
	void	doubleClick(QListWidgetItem *);
	void	addWindowFunc();
	void	delWindowFunc();
	void	sendRequestToServer();
	void	showAPropos();
};

