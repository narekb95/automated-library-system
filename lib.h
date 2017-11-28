#ifndef LIB_H
#define LIB_H
#include "user.h"
#include "book.h"
#include<functional>
#include<map>
const int MAX_REQ = 50;
const int MAX_BORROW = 50;
class LibOrganizer
{
public:
	enum class LibExceptions{bookNotFound, bookNotAvailable, bookTitleAlreadyExists, bookISBNAlreadyExists, bookAlreadyBought, userAlreadyExists, userNotFound};
    
	LibOrganizer(std::function<void(Book)> buyBookFunction = defaultBuyBookFunction);

	Book& findBookPerTitle(const std::string& title);
	Book& findBookPerISBN(const std::string& ISBN);
	Book& buyBook(std::string title, std::string author, std::string ISBN);
    
	void borrowBook(std::string userName, std::string bookTitle);
	void returnBook(std::string userName, std::string bookTitle);
	void requestBook(std::string BookTitle, std::string author, std::string ISBN);
	void requestBook(Book& book);
	User& addUser(std::string name);
    
private:
    std::function<void(Book)> buyBookFunction;
    std::map<std::string, Book> booksISBNIndex;
    std::map<std::string, User> userNameIndex;
    std::map<std::string, std::map<std::string, Book>::iterator> booksTitleIndex;
    
	Book& addBook(std::string title, std::string author, std::string ISBN, Book::BookStatus status);
	static void defaultBuyBookFunction(Book book);
    void removeBook(Book& book);
    void borrowBook(User& user, Book& book);

};
#endif
