#ifndef PROTOCOL_H_
# define PROTOCOL_H_
#include <stdint.h>

namespace Protocol
{
	typedef enum Specification
	{
		CONNECT_DONE = 0,
		CONNECT_DENIED,
		DISCONNECT_INC,
		CALL_INCOMING,
		DECLINED_CALL,
		ASK_CONTACT,
		ACCEPTED_CONTACT,
		REFUSED_CONTACT,
		CONNECT_REQUEST,
		DISCONNECT_REQUEST,
		SIGN_IN,
		CALL_CONTACT,
		TAKE_CALL,
		DECLINE_CALL,
		ADD_CONTACT,
		ACCEPT_CONTACT,
		REFUSE_CONTACT,
		DELETE_CONTACT,
		CALL_DATA,
		SERVER_CREATED,
		HANGOUT,
	}			Spef;

	typedef struct RequestData
	{
		char		Source[20];
		char		Dest[20];
		uint32_t	Pwd;
		uint32_t	Spef;
	}				RequestData;

	typedef struct CallData
	{
		uint32_t	Type;
		uint32_t	Source;
		uint32_t	Dest;
		uint32_t	Size;
		char		Data[1105];
	}				CallData;
}

#endif