#include"lib.h"
#include<iostream>
void LibOrganizer::defaultBuyBookFunction(Book book)
{
	cout << "please buy the following book " + book.toString() << endl;
}

LibOrganizer::LibOrganizer(std::function<void(Book)> buyBookFunction) : buyBookFunction(buyBookFunction)
{
}

Book& LibOrganizer::addBook(std::string title, std::string author, std::string ISBN, std::string status)
{
	if(booksTitleIndex.count(title))
	{
		throw LibException::bookTitleAlreadyExists;
	}
	if(booksISBNIndex.count(ISBN))
	{
		throw libException::bookISBNAlreadyExists;
	}
	Book book(title, author, ISBN, status);
	booksISBNIndex[ISBN] = std::move(book);
	booksTitleIndex[title] = booksISBNIndex[book];
	return booksISBNIndex[ISBN];
}

User& LibOrganizer::addUser(std::string name)
{
	if(userNameIndex.count(name)
	{
		throw libException::userAlreadyExists;
	}
	User user(name);
	userNameIndex[name] = std::move(user);
	return userNameIndex[name];
}

Book& LibOrganizer::findBookPerTitle(const std::string& title)
{
	if(!booksTitleIndex.count(title)){
		throw libExcpetions::bookNotFound;
	return booksTitleIndex[*title];
}

Book& LibOrganizer::findBookPerISBN(const std::string& ISBN)
{
	if(!bookISBNIndex.count(ISBN))
		throw libExceptions::bookNotFound;
	return bookISBNIndex[ISBN];
}

void LibOrganizer::borrowBook(std::string userName, std::string bookTitle)
{
	User& user = userNameIndex[userName];
	Book& book = *bookTitleIndex[bookTitle];
	borrowBook(user, book);
}

void LibOrganizer::borrowBook(User& user, Book& bookTitle)
{
	try
	{
		user.borrowBook(book);
		book.borrow(user);
	}
	catch (Book::BookException::notAvailable)
	{
		user.returnBook(book);
	}
	catch (User::UserException::reachedMaxNumberOfBooks)
	{
		book.returnBook(book);
	}
}

void LibOrganizer::returnBook(std::string userName, std::string bookTitle)
{
	User& user = userNameIndex[userName];
	Book& book = *bookTitleIndex[bookTitle];
	returnBook(user, book);
}

void LibOrganizer::returnBook(User& user, Book& book)
{
	user.returnBook(book);
	book.returnBook(user);
}
