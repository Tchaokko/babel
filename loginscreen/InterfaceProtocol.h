#pragma once
#include "Protocol.h"

class InterfaceProtocol
{

protected:
	
	virtual bool	sendRequest(Protocol::RequestData const &) = 0;
	virtual bool	sendCallData(Protocol::CallData const &) = 0;
	virtual bool	processRequest(Protocol::RequestData const &) = 0;
	virtual bool	processCallData(Protocol::CallData const &) = 0;
};

