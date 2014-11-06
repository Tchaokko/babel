#include "HandleSocket.h"
#include "HandleProtocol.h"
#include <iostream>


void		HandleSocket::processData()
{
	QByteArray				buffer;
	QHostAddress			sender;
	quint16					senderPort;
	quint32					type;
	Protocol::CallData		data;
	char					*tmp = reinterpret_cast<char*>(&data);
	int						count = 0;

	buffer.resize(sizeof(this->Call));
	this->udpSocket->readDatagram(buffer.data(), buffer.size(), &sender, &senderPort);
	if (!buffer.isEmpty())
	{
		while (count != sizeof(data))
		{
			tmp[count] = buffer.at(count);
			++count;
		}
	}
	this->protocolHandler->processData(data);
}


void		HandleSocket::processInfo()
{
	QByteArray				buffer;
	QHostAddress			sender;
	quint16					senderPort;
	Protocol::RequestData	data;
	char					*tmp = reinterpret_cast<char*>(&data);
	int						count = 0;

	buffer.resize(sizeof(this->Request));
	buffer = this->tcpSocket->read(sizeof(this->Request));

	if (!buffer.isEmpty())
	{
		while (count != sizeof(data))
		{
			tmp[count] = buffer.at(count);
			++count;
		}
	}
	this->protocolHandler->processRequest(data);
}

void		HandleSocket::initSocket()
{
	this->hostAdress.setAddress(this->ip);
	this->udpSocket->bind(this->hostAdress, 2520);
	this->tcpSocket->bind(this->hostAdress, 4045);
}

HandleSocket::HandleSocket()
{
	this->tcpSocket = new QTcpSocket(0);
	this->udpSocket = new QUdpSocket(0);
	this->protocolHandler = new HandleProtocol();


	
	connect(this->udpSocket, SIGNAL(readyRead()), this, SLOT(processData()));
	connect(this->tcpSocket, SIGNAL(readyRead()), this, SLOT(processInfo()));
}


HandleSocket::~HandleSocket()
{
}
