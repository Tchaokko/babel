#pragma once
#include <QtNetwork\qtcpsocket.h>
#include <QtNetwork\qudpSocket.h>
#include <QtWidgets\qmainwindow.h>
#include <HandleProtocol.h>
#include <Protocol.h>

class HandleSocket : public QMainWindow
{

	Q_OBJECT

	typedef union Convert
	{
		char	tmp[4];
		quint32	type;
	} Convert;

public:
	HandleSocket();
	~HandleSocket();
public:
	void		initSocket();

private:

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

