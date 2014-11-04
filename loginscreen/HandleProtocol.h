#ifndef HANDLEPROTOCOL
# define HANDLEPROTOCOL
# include "Protocol.h"

class HandleProtocol
{
	Protocol::RequestData	_requestData;
	Protocol::CallData		_data;
public:
	HandleProtocol();
	~HandleProtocol();
	bool	sendRequest(Protocol::RequestData const &data);
	bool	sendData(Protocol::CallData const &data);
	bool	readRequest();
	bool	processRequest(Protocol::RequestData const &);
	bool	processData(Protocol::CallData const &);
};

#endif /* HANDLEPROTOCOL */