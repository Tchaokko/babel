#pragma once
#include <QtNetwork\qtcpsocket.h>
#include <QtNetwork\qudpSocket.h>
#include <QtWidgets\qmainwindow.h>
#include <HandleProtocol.h>
#include <Protocol.h>
#include <qlineedit.h>
#include "InternalProtocol.h"

class HandleSocket : public QMainWindow
{

	Q_OBJECT

public:
	HandleSocket(QLineEdit&);
	~HandleSocket();
public:
	void						initSocket();
	bool						initSocketTcp(QString const &ip);
	bool						writeOnTcp();
	Protocol::RequestData		getRequest();
private:

	QLineEdit				&_action;
	Protocol::RequestData	Request;
	Protocol::CallData		Call;
	HandleProtocol			*protocolHandler;
	QHostAddress			hostAdress;
	QTcpSocket				*tcpSocket;
	QUdpSocket				*udpSocket;

public slots:
	void	processData();
	void	processInfo();
};

