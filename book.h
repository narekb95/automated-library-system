#ifndef BOOK_H
#define BOOK_H
#include<string>
#include"user.h"
#include<vector>
class Book
{
public:
	Book(std::string title, std::string author, std::string ISBN);
	void request();
	std::string getTitle();
	bool isAvailable();
	bool borrow(User* user);
	void addUser(User* user);
private:
	std::string title;
	std::string author;
	std::string ISBN;
	int totalCopies;
	int borrowedCopies;
	int numberOfRequests;
	std::vector<User*> users;
}//you cam make a constructor with a call-function to call when requests reach a point to buy
#endif
