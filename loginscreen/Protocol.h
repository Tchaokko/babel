#pragma once

#include <stdint.h>

namespace Protocol
{
	typedef enum Spefication
	{
		CONNECT = 1,
		CONNECT_DONE,
		CONNECT_DENIED,
		DISCONNECT,
		SIGN_IN,
		CALL,
		CALL_INCOMING,
		TAKE_CALL,
		DECLINE_CALL,
		DECLINED_CALL,
		ADD_CONTACT,
		ACCEPT_CONTACT,
		ACCEPTED_CONTACT,
		REFUSE_CONTACT,
		REFUSED_CONTACT,
	}Spef;

	typedef	enum Type
	{
		CONNECT = 1,
		CALL,
		DATA,
		CONTACT,
	}Type;

	struct Connect
	{
		uint32_t	Type;
		uint32_t	Source;
		uint32_t	Pwd;
		uint32_t	Spef;
	};

	struct Call
	{
		uint32_t	Type;
		uint32_t	Source;
		uint32_t	Dest;
		uint32_t	Spef;
	};

	struct Data
	{
		uint32_t	Type;
		uint32_t	Source;
		uint32_t	Dest;
		uint32_t	Size;
		char		Data[1105];
	};

	struct Contact
	{
		uint32_t	Type;
		uint32_t	Source;
		uint32_t	Dest;
		uint32_t	Spef;
	};
}