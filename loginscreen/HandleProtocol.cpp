#include "HandleProtocol.h"

bool	HandleProtocol::processRequest(Protocol::RequestData const &data)
{	
	if (data.Type == Protocol::CONNECT)
	return true;
}

bool	HandleProtocol::processData(Protocol::CallData const &data)
{
	return true;
}

bool	HandleProtocol::readRequest()
{
	return true;
}

bool	HandleProtocol::sendData(Protocol::CallData const &data)
{
	return true;
}

bool	HandleProtocol::sendRequest(Protocol::RequestData const &data)
{
	return true;
}

HandleProtocol::HandleProtocol()
{
}

HandleProtocol::~HandleProtocol()
{
}
