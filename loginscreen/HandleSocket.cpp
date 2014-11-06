#include "HandleSocket.h"
#include "HandleProtocol.h"


void		HandleSocket::processData()
{
	QByteArray buffer;
	QHostAddress	sender;
	quint16		senderPort;

	buffer.resize(sizeof(this->Call));
	this->udpSocket->readDatagram(buffer.data(), buffer.size(), &sender, &senderPort);


	
}


void		HandleSocket::processInfo()
{
	QByteArray		buffer;
	QHostAddress	sender;
	quint16			senderPort;

	buffer.resize(sizeof(this->Request));

}

HandleSocket::HandleSocket(QString ip, QString port)
{
	this->tcpSocket = new QTcpSocket(0);
	this->udpSocket = new QUdpSocket(0);
	this->protocolHandler = new HandleProtocol();

	this->hostAdress.setAddress(ip);
	this->udpSocket->bind(this->hostAdress, 2520);
	this->tcpSocket->bind(this->hostAdress, 4045);
	
	connect(this->udpSocket, SIGNAL(readyRead()), this, SLOT(processData()));
	connect(this->tcpSocket, SIGNAL(readyRead()), this, SLOT(processInfo()));
}


HandleSocket::~HandleSocket()
{
}
