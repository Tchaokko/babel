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
	~HandleProtocol();
	bool	sendRequest(Protocol::RequestData const &data);
	bool	sendData(Protocol::CallData const &data);
	bool	processRequest(Protocol::RequestData const &);
	bool	processData(Protocol::CallData const &);
};

#endif /* HANDLEPROTOCOL */