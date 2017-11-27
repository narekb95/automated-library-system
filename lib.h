#ifndef LIB_H
#define LIB_H
#include "user.h"
#include "book.h"
#include<functional>
#include<map>
class LibOrganizer
{
public:
	enum class LibExceptions{bookNotFound, bookNotAvailable, bookTitleAlreadyExists, bookISBNAlreadyExists, userAlreadyExists}
	LibOrganizer(std::function<void(Book)> buyBookFunction = defualtBuyBookFunction);

	Book& findBookPerTitle(const std::string& title);
	Book& findBookPerISBN(const std::string& ISBN);
	void borrowBook(std::string userName, std::string bookTitle);
	void borrowBook(User& user, Book& book);
	void returnBook(std::string userName, std::string bookTitle);
	void returnBook(User& user, Book& book);
	void addBook(std::string title, std::string author, std::string ISBN, BookStatus status);
	void addUser(std::string name);
private:
	std::map<std::string, Book*> booksTitleIndex;
	std::map<std::string, Book> booksISBNIndex;
	std::map<std::string, user> userNameIndex;
	static void defaultBuy(Book book);
	void removeBook(std::string identifier, bool 
	static void defaultBuyBookFunction(Book book);
	static std::function<void(Book)> buyBookFunction;

}
#endif
