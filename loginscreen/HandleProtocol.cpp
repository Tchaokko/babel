#include "HandleProtocol.h"

void	HandleProtocol::connectDone(Protocol::RequestData const &data)
{

}

void	HandleProtocol::connectDenied(Protocol::RequestData  const &data)
{

}

void	HandleProtocol::disconnectIncoming(Protocol::RequestData const &data)
{

}

void	HandleProtocol::callIncoming(Protocol::RequestData const &data)
{

}

void	HandleProtocol::declinedCall(Protocol::RequestData const &data)
{

}

void	HandleProtocol::askContact(Protocol::RequestData const &data)
{

}

void	HandleProtocol::acceptedContact(Protocol::RequestData const &data)
{

}

void	HandleProtocol::refusedContact(Protocol::RequestData const &data)
{

}

void	HandleProtocol::connectServ(Protocol::Spef Type, uint32_t Dest)
{

}

void	HandleProtocol::signIn(Protocol::Spef Type, uint32_t Dest)
{

}

void	HandleProtocol::call(Protocol::Spef Type, uint32_t Dest)
{

}

void	HandleProtocol::takeCall(Protocol::Spef Type, uint32_t Dest)
{

}

void	HandleProtocol::declineCall(Protocol::Spef Type, uint32_t Dest)
{

}

void	HandleProtocol::addContact(Protocol::Spef Type, uint32_t Dest)
{

}

void	HandleProtocol::acceptContact(Protocol::Spef Type, uint32_t Dest)
{

}

void	HandleProtocol::refuseContact(Protocol::Spef Type, uint32_t Dest)
{

}

bool	HandleProtocol::processRequest(Protocol::RequestData const &data)
{	
	for (int count = 0; count < 8; count++)
	{
		if (data.Spef == count)
			processFunction[count](data);
	}

	return true;
}

bool	HandleProtocol::processCallData(Protocol::CallData const &data)
{
	return true;
}


bool	HandleProtocol::sendCallData(Protocol::CallData const &data)
{
	return true;
}

bool	HandleProtocol::sendRequest(Protocol::Spef Type, uint32_t Dest)
{
	for (int count = 8; count < 16; count++)
	{
		if (Type == count)
			sendFunction[count](Type, Dest);
	}
	return true;
}

void		HandleProtocol::processData()
{
	QByteArray				buffer;
	QHostAddress			sender;
	quint16					senderPort;
	quint32					type;
	Protocol::CallData		data;
	char					*tmp = reinterpret_cast<char*>(&data);
	int						count = 0;

	buffer.resize(sizeof(this->_requestData));
	this->udpSocket->readDatagram(buffer.data(), buffer.size(), &sender, &senderPort);
	if (!buffer.isEmpty())
	{
		while (count != sizeof(data))
		{
			tmp[count] = buffer.at(count);
			++count;
		}
	}
	this->processCallData(data);
}

void		HandleProtocol::processInfo()
{
	QByteArray				buffer;
	QHostAddress			sender;
	quint16					senderPort;
	Protocol::RequestData	data;
	char					*tmp = reinterpret_cast<char*>(&data);
	int						count = 0;

	buffer.resize(sizeof(this->_requestData));
	buffer = this->tcpSocket->read(sizeof(this->_requestData));

	if (!buffer.isEmpty())
	{
		while (count != sizeof(data))
		{
			tmp[count] = buffer.at(count);
			++count;
		}
	}
	this->processRequest(data);
}

void		HandleProtocol::initSocket()
{
	this->hostAdress.setAddress("");
	this->udpSocket->bind(this->hostAdress, 2520);
	this->tcpSocket->bind(this->hostAdress, 4045);
}

HandleProtocol::HandleProtocol()
{
	this->tcpSocket = new QTcpSocket(0);
	this->udpSocket = new QUdpSocket(0);

	processFunction.push_back(HandleProtocol::connectDone);
	processFunction.push_back(HandleProtocol::connectDenied);
	processFunction.push_back(HandleProtocol::disconnectIncoming);
	processFunction.push_back(HandleProtocol::callIncoming);
	processFunction.push_back(HandleProtocol::declinedCall);
	processFunction.push_back(HandleProtocol::askContact);
	processFunction.push_back(HandleProtocol::acceptedContact);
	processFunction.push_back(HandleProtocol::refusedContact);

	sendFunction.push_back(HandleProtocol::connectServ);
	sendFunction.push_back(HandleProtocol::disconnectSend);
	sendFunction.push_back(HandleProtocol::signIn);
	sendFunction.push_back(HandleProtocol::call);
	sendFunction.push_back(HandleProtocol::takeCall);
	sendFunction.push_back(HandleProtocol::declineCall);
	sendFunction.push_back(HandleProtocol::addContact);
	sendFunction.push_back(HandleProtocol::acceptContact);
	sendFunction.push_back(HandleProtocol::refuseContact);
	
	connect(this->udpSocket, SIGNAL(readyRead()), this, SLOT(processData()));
	connect(this->tcpSocket, SIGNAL(readyRead()), this, SLOT(processInfo()));
}

HandleProtocol::~HandleProtocol()
{
}
