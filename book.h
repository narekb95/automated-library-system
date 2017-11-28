#ifndef BOOK_H
#define BOOK_H
#include<string>
#include<vector>
#include<map>
class User;
class Book
{
public:
	enum class BookException { notAvailable, notInRequest, hasBeenRequestedFromThisUser};
	enum class BookStatus { available, borrowed, inRequest};
	Book(std::string title, std::string author, std::string ISBN, BookStatus status);
	Book() = default;
	void request(User* user);
	std::string getTitle();
	bool isAvailable();
	void borrow(User* user);
	int returnBook();
	bool operator<(const Book& rhs) const;
	bool operator ==(const Book& rhs) const;
	void buyFromWaitingList();
	std::string toString();
	User* getUser();
	std::string getTitle() const;
	std::string getISBN() const;
    std::string getAuthor() const;
	BookStatus getStatus() const;
	int request();

private:
	int numOfUses;
	int numOfRequests;
	std::string title;
	std::string author;
	std::string ISBN;
	User* user;
	BookStatus status;
	int numberOfRequests;
	std::map<User*, bool> requestMaker;
};
#endif
