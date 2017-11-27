#ifndef LIB_H
#define LIB_H
#include "user.h"
#include "book.h"
#include<set>
#include<function>
class LibOrganizer
{
public:
	LibOrganizer(std::function<void(Book)> buyBookFunction = defualtBuyBookFunction);
	enum class libExceptions{bookNotFound, bookNotAvailable, bookAlreadyExists, userAlreadyExists}
	Book findBookPerTitle(std::string title);
	Book findBookPerISBN(std::string ISBN);
	void borrow(User user, Book book);
private:
	std::map<std::string, Book*> booksTitleIndex;
	std::map<std::string, Book> booksISBNIndex;
	static void defaultBuy(Book book);
	void addBook(std::string title, std::string author, std::string ISBN, BookStatus status);
	void removeBook(std::string identifier, bool 
	static void defaultBuyBookFunction(Book book);
	static std::function<void(Book)> buyBookFunction;

}
#endif
