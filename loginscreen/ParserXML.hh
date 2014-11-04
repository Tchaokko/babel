#ifndef		__PARSERXML_HH__
# define	__PARSERXML_HH__

# include	<string>
# include	<iostream>
# include	<fstream>
# include	<list>

// need this include for use stat 
// in function :  bool fileIsExist(std::string const &);
# include	<sys/stat.h>
# include	<stdint.h>

# define	FILE_EXTENSION	(".babel")

class ParserXML
{
public:
	ParserXML();
	~ParserXML();

	bool	fileIsExist(std::string const &);
	void	createUser(std::string const &);
	void	addFriend(std::string const &, std::string const &);
	void	removeFriend(std::string const &, std::string const &);
	std::list<std::string>	listOfFriend(std::string const &);
private:
	const int	FILE_DONT_EXIST;
};

#endif		// !__PARSERXML_HH__