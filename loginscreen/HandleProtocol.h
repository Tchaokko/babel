#ifndef HANDLEPROTOCOL
# define HANDLEPROTOCOL
# include "Protocol.h"
#include "InterfaceProtocol.h"

class HandleProtocol : public InterfaceProtocol
{
	Protocol::RequestData	_requestData;
	Protocol::CallData		_data;
public:
	HandleProtocol();
	virtual ~HandleProtocol();
	virtual bool	sendRequest(Protocol::RequestData const &data);
	virtual bool	sendCallData(Protocol::CallData const &data);
	virtual bool	processRequest(Protocol::RequestData const &);
	virtual bool	processCallData(Protocol::CallData const &);
};

#endif /* HANDLEPROTOCOL */