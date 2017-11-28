#ifndef LIB_H
#define LIB_H
#include "user.h"
#include "book.h"
#include<functional>
#include<map>
const int MAX_REQ = 50;
class LibOrganizer
{
public:
	enum class LibExceptions{bookNotFound, bookNotAvailable, bookTitleAlreadyExists, bookISBNAlreadyExists, bookAlreadyBought, userAlreadyExists};
	LibOrganizer(std::function<void(Book)> buyBookFunction = defaultBuyBookFunction);

	Book& findBookPerTitle(const std::string& title);
	Book& findBookPerISBN(const std::string& ISBN);
	Book& buyBook(std::string title, std::string author, std::string ISBN);
	void borrowBook(std::string userName, std::string bookTitle);
	void borrowBook(User& user, Book& book);
	void returnBook(std::string userName, std::string bookTitle);
	void returnBook(User& user, Book& book);
	void removeBook(Book book);
	void requestBook(std::string BookTitle, std::string author, std::string ISBN);
	void requestBook(Book& book);
	User& addUser(std::string name);
private:
	Book& addBook(std::string title, std::string author, std::string ISBN, Book::BookStatus status);
	std::map<std::string, std::map<std::string, Book>::iterator> booksTitleIndex;
	std::map<std::string, Book> booksISBNIndex;
	std::map<std::string, User> userNameIndex;
	static void defaultBuyBookFunction(Book book);
	std::function<void(Book)> buyBookFunction;

};
#endif
