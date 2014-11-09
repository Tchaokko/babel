#include "HandleSocket.h"
#include "HandleProtocol.h"
#include <iostream>
#include <sstream>

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
}


void		HandleSocket::processInfo()
{
	int nb = InternalProtocol::INC_REQUEST;
	std::stringstream		stream;
	stream << nb;
	std::string				str(stream.str());
	QString					proto(str.c_str());
	QByteArray				buffer;
	QHostAddress			sender;
	quint16					senderPort;
	Protocol::RequestData	data;
	char					*tmp = reinterpret_cast<char*>(&this->Request);
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
	this->_action.setText(proto);
}

Protocol::RequestData		HandleSocket::getRequest()
{
	return this->Request;
}

void		HandleSocket::initSocket()
{
	this->hostAdress.setAddress("");
	this->udpSocket->bind(this->hostAdress, 2520);
	this->tcpSocket->bind(this->hostAdress, 4045);
}

HandleSocket::HandleSocket(QLineEdit &action) : _action(action)
{
	this->tcpSocket = new QTcpSocket(0);
	this->udpSocket = new QUdpSocket(0);

	
	connect(this->udpSocket, SIGNAL(readyRead()), this, SLOT(processData()));
	connect(this->tcpSocket, SIGNAL(readyRead()), this, SLOT(processInfo()));
}


HandleSocket::~HandleSocket()
{
}
