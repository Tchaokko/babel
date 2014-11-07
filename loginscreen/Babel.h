#pragma once

#include <qobject.h>
#include <qlistwidget.h>
#include <HandleSocket.h>
#include <HandleProtocol.h>
#include <InterfaceProtocol.h>

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
	QString			field1;
	QString			field2;
	QString			field3;

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

