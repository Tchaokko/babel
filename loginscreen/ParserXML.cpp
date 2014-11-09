#include "ParserXML.hh"

ParserXML::ParserXML() : FILE_DONT_EXIST(-1)
{

}


ParserXML::~ParserXML()
{

}

bool	isFriendInTheList(std::string const &)
{

}

bool	ParserXML::fileIsExist(std::string const & user)
{
	struct stat	buffer;
	std::string file;

	file = user + FILE_EXTENSION;
	if (stat(file.c_str(), &buffer) != FILE_DONT_EXIST) {
		return (true);
	}
	return (false);
}

void	ParserXML::createUser(std::string const & nameUser)
{
	std::fstream	file;
	std::string		fileName;

	fileName = nameUser + FILE_EXTENSION;	
	if ((fileIsExist(nameUser)) == true)
		return ;
	file.open(fileName, std::fstream::in | std::fstream::out | std::fstream::app);
	file << "<client>\n<name=" << nameUser << ">\n</client>" << std::endl;
	file.close();
}

void	ParserXML::addFriend(std::string const & nameFriend,
								   std::string const & nameUser)
{
	std::fstream	file;
	std::string		fileName;

	fileName = nameUser + FILE_EXTENSION;
	if ((fileIsExist(nameUser)) == false)
		return;
	file.open(fileName, std::fstream::in | std::fstream::out | std::fstream::app);
	file << "<friend=" << nameFriend << ">" << std::endl;
	file.close();
}


std::list<std::string>	ParserXML::listOfFriend(std::string const & nameUser)
{
	std::ifstream	file;
	std::string		fileName;
	std::string		tmp;
	std::list<std::string> friendsList;
	uint8_t			numLine = 0;

	fileName = nameUser + FILE_EXTENSION;
	if ((fileIsExist(nameUser)) == false)
		return (friendsList);
	file.open(fileName);
	if (!file.is_open())
		return (friendsList);
	while (!file.eof())
	{
		file >> tmp;
		if (numLine >= 3 && tmp.length() > 9)
			{
				tmp.erase(0, 8);
				tmp.pop_back();
				friendsList.push_back(tmp);
			}
		tmp.clear();
		++numLine;
	}
	file.close();
	return (friendsList);
}

bool	ParserXML::isFriendInTheList(std::string const &nameUser, std::string const &nameTarget)
{
	std::list<std::string>				friendsList = this->listOfFriend(nameUser);
	std::list<std::string>::iterator	it;
	std::string							currentFriend;

	for (it = friendsList.begin(); it != friendsList.end(); ++it)
	{
		currentFriend = *it;
		if (currentFriend.compare(nameTarget) == 0)
			return true;
	}
	return false;
}

void		ParserXML::removeFriend(std::string const & nameFriend,
									std::string const & nameUser)
{
	std::list<std::string>	friendsList;
	std::list<std::string>::iterator it;
	std::string				currentFriend;
	std::string				fileName;
	
	fileName = nameUser + FILE_EXTENSION;
	friendsList = listOfFriend(nameUser);
	friendsList.remove(nameFriend);
	if ((std::remove(fileName.c_str())) != 0)
		return;
	createUser(nameUser);
	for (it = friendsList.begin(); it != friendsList.end(); ++it)
	{
		currentFriend = *it;
		addFriend(currentFriend, nameUser);
	}
}