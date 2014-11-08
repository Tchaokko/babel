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

HandleProtocol::HandleProtocol()
{
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
}

HandleProtocol::~HandleProtocol()
{
}
