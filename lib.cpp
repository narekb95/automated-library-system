#include"lib.h"
#include<iostream>
void LibOrganizer::defaultBuyBookFunction(Book book)
{
	std::cout << "please buy the following book " + book.toString() << std::endl;
}

LibOrganizer::LibOrganizer(std::function<void(Book)> buyBookFunction) : buyBookFunction(buyBookFunction)
{
}

Book& LibOrganizer::addBook(std::string title, std::string author, std::string ISBN, Book::BookStatus status)
{
	if(booksTitleIndex.count(title))
	{
		throw LibExceptions::bookTitleAlreadyExists;
	}
	if(booksISBNIndex.count(ISBN))
	{
		throw LibExceptions::bookISBNAlreadyExists;
	}
	Book book(title, author, ISBN, status);
	booksISBNIndex[ISBN] = book;
	booksTitleIndex[title] = booksISBNIndex.find(ISBN);
	return booksISBNIndex[ISBN];
}

User& LibOrganizer::addUser(std::string name)
{
	if(userNameIndex.count(name))
	{
		throw LibExceptions::userAlreadyExists;
	}
	User user(name);
	userNameIndex[name] = user;
	return userNameIndex[name];
}

Book& LibOrganizer::findBookPerTitle(const std::string& title)
{
	if(!booksTitleIndex.count(title)){
		throw LibExceptions::bookNotFound;
	}
	return booksTitleIndex[title]->second;
}

Book& LibOrganizer::findBookPerISBN(const std::string& ISBN)
{
	if(!booksISBNIndex.count(ISBN))
		throw LibExceptions::bookNotFound;
	return booksISBNIndex[ISBN];
}

void LibOrganizer::borrowBook(std::string userName, std::string bookTitle)
{
	User& user = userNameIndex[userName];
	Book& book = findBookPerTitle(bookTitle);
	borrowBook(user, book);
}

void LibOrganizer::borrowBook(User& user, Book& book)
{
	try
	{
		user.borrowBook(&book);
		book.borrow(&user);
	}
	catch (Book::BookException bookExp)
	{
		if(bookExp == Book::BookException::notAvailable)
		{
			user.returnBook(&book);
		}
		throw bookExp;
	}
	catch (User::UserException userExp)
	{
		if(userExp == User::UserException::reachedMaxNumberOfBooks)
		{
			book.returnBook();
		}
		throw userExp;
	}
}

void LibOrganizer::returnBook(std::string userName, std::string bookTitle)
{
	User& user = userNameIndex[userName];
	Book& book = findBookPerTitle(bookTitle);
	returnBook(user, book);
}

void LibOrganizer::returnBook(User& user, Book& book)
{
	user.returnBook(&book);
	book.returnBook();
}
