#pragma once

class InterfaceProtocol
{

public:

	virtual ~InterfaceProtocol() = 0;
protected:
	
	virtual void	sendRequest() = 0;
	virtual void	sendCallData() = 0;
	virtual void	processRequest() = 0;
	virtual void	processCallData() = 0;
};

