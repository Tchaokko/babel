#ifndef HANDLEPROTOCOL
# define HANDLEPROTOCOL
# include "Protocol.h"
#include "InterfaceProtocol.h"
#include <vector>

class HandleProtocol : public InterfaceProtocol
{
	Protocol::RequestData	_requestData;
	Protocol::CallData		_data;
	std::vector<void(*)(Protocol::Spef, uint32_t) >	sendFunction;
	std::vector<void(*)(Protocol::RequestData const &data) >	processFunction;
	
public:
	HandleProtocol();
	virtual ~HandleProtocol();

	virtual bool	sendRequest(Protocol::Spef , uint32_t);
	virtual bool	sendCallData(Protocol::CallData const &data);
	virtual bool	processRequest(Protocol::RequestData const &);
	virtual bool	processCallData(Protocol::CallData const &);

	static	void	connectDone(Protocol::RequestData const &data);
	static	void	connectDenied(Protocol::RequestData const &data);
	static	void	disconnectIncoming(Protocol::RequestData const &data);
	static	void	callIncoming(Protocol::RequestData const &data);
	static	void	declinedCall(Protocol::RequestData const &data);
	static	void	askContact(Protocol::RequestData const &data);
	static	void	acceptedContact(Protocol::RequestData const &data);
	static	void	refusedContact(Protocol::RequestData const &data);

	static	void	connectServ(Protocol::Spef, uint32_t);
	static	void	disconnectSend(Protocol::Spef, uint32_t);
	static	void	signIn(Protocol::Spef, uint32_t);
	static	void	call(Protocol::Spef, uint32_t);
	static	void	takeCall(Protocol::Spef, uint32_t);
	static	void	declineCall(Protocol::Spef, uint32_t);
	static	void	addContact(Protocol::Spef, uint32_t);
	static	void	acceptContact(Protocol::Spef, uint32_t);
	static	void	refuseContact(Protocol::Spef, uint32_t);


};

#endif /* HANDLEPROTOCOL */