#pragma once

namespace InternalProtocol
{
	typedef enum SpecificationSocket
	{

	}SpefSock;

	typedef enum SpecificationConfWindow
	{
		HANGOUT = 1,
	}ConfWin;

	typedef enum SpecificationAddWindow
	{
		ADD_CONTACT = 1,
	}SpefAddWin;

	typedef	enum SpecificationDelWindow
	{
		DEL_CONTACT = 1,
	}SpefDelWin;
	
	typedef	enum SpecificationMainMenu
	{
		POP_ADD_CONTACT = 1,
		POP_DEL_CONTACT,
		POP_CALL_CONTACT,
		POP_APROPOS
	}SpefMainMenu;

	typedef enum SpecificationIncomingCallWindow
	{
		ACCEPT_CALL = 1,
		DENY_CALL,
	}SpefIncCallWin;

	typedef	enum SpecificationCallWindow
	{
		CALL_CONTACT = 1,
	}SpefCallWin;

	typedef enum SpeficifationLoginScreen
	{
		LOG_IN = 1,
		SIGN_IN
	}SpefLogin;
}