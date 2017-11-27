#ifndef USER_H
#define USER_H
#include<string>
#include<map>
#include<vector>
#include"book.h"
class User
{
public:
	enum class UserException {reachedMaxNumberOfBooks};
	User(std::string name);
	~User();
	bool operator== (const User& rUsr);
	bool operator< (const User& rUsr);
	std::string getName();
	void borrowBook(Book* book);
	void returnBook(Book* book);
private:
	std::string name;
	std::vector<Book*> borrowedBooks;
	int numOfBooks;
};
#endif
