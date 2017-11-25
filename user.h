#ifndef USER_H
#define USER_H
#include<string>
#include<map>
#include<vector>
#include"book.h"
class User
{
public:
	User(std::string name);
	~User();
	bool operator== (const User& rUsr);
	bool operator< (const User& rUsr);
	std::string getName();
	std::string searchName();
	bool borrowBook(std::string bookTitle);
	bool returnBook(std::string bookTitle);
	bool borrowBook(Book* book);
	bool returnBook(Book* book);
private:
	std::string name;
	std::string globalUniqueUserId;
	static std::map<std::string, const User*> usedIds;
	std::string generateId();
	std::vector<Book*> borrowedBooks;
	int numOfBooks;
};
#endif
