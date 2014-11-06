#pragma once

#include <QtNetwork\qtcpserver.h>
#include <QtNetwork\qudpsocket.h>

class Network
{
public:
	Network();
	~Network();

private:
	QTcpSocket		*tcpSocket;
	QUdpSocket		*udpSocket;

};

