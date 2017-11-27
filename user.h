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
	enum class userException {usedNameException, reachedMaxNumberOfBooks, noSuchBookInRepo};
	bool operator== (const User& rUsr);
	bool operator< (const User& rUsr);
	std::string getName();
	bool borrowBook(std::string bookTitle);
	void returnBook(std::string bookTitle);
	void borrowBook(Book* book);
	bool returnBook(Book* book);
private:
	std::string name;
	std::vector<Book*> borrowedBooks;
	int numOfBooks;
};
#endif
