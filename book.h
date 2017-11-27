#ifndef BOOK_H
#define BOOK_H
#include<string>
#include<vector>
#include<map>
class User;
class Book
{
public:
	enum class BookException { notAvailable};
	enum class BookStatus { available, borrowed, inRequest};
	Book(std::string title, std::string author, std::string ISBN, BookStatus status);
	void request(std::string user);
	std::string getTitle();
	bool isAvailable();
	void borrow(User* user);
	int returnBook();
	bool operator<(const Book& rhs) const;
	std::string toString();

private:
	int numOfUses;
	std::string title;
	std::string author;
	std::string ISBN;
	User* user;
	BookStatus status;
	int numberOfRequests;
	std::map<std::string, bool> requestMaker;
};
#endif
