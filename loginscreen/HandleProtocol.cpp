#include "HandleProtocol.h"

bool	HandleProtocol::processRequest(Protocol::RequestData const &data)
{	
	//if (data.Type == Protocol::CONNECT)
		return true;
	return false;
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
