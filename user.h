#ifndef USER_H
#define USER_H
#include<string>
#include<map>
#include<vector>
class User
{
public:
	User(std::string name);
	bool operator== (const User& rUsr);
	bool operator< (const User& rUsr);
	std::string getName();
	std::string searchName();
	bool borrowBook(std::string bookName);
	bool returnBook(std::string bookName);
private:
	std::string name;
	std::string globalUniqueUserId;
	static std::map<std::string, const User*> usedIds;
	std::string generateId();
	std::vector<std::string> borrowedBooks;
	int numOfBooks;
};
#endif
