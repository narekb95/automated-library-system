#ifndef USER_H
#define USER_H
#include<string>
#include<vector>
#include"book.h"
class User
{
public:
	enum class UserException {reachedMaxNumberOfBooks};
	User(std::string name);
	User() = default;
	bool operator== (const User& rUsr);
	bool operator< (const User& rUsr);
	std::string getName();
	void borrowBook(Book* book);
	void returnBook(Book* book);
	std::string toString();
private:
	std::string name;
	std::vector<Book*> borrowedBooks;
	int numOfBooks;
};
#endif
