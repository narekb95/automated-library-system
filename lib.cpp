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
	return std::ref(userNameIndex[name]);
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
	if(!userNameIndex.count(userName))
	{
		throw LibExceptions::userNotFound;
	}
	User& user = userNameIndex[userName];
	Book& book = findBookPerTitle(bookTitle);
	borrowBook(std::ref(user), std::ref(book));
}

void LibOrganizer::borrowBook(User& user, Book& book)
{
	try
	{
		user.borrowBook(std::ref(book));
		book.borrow(&user);
	}
	catch (Book::BookException bookExp)
	{
		try
		{
			user.returnBook(std::ref(book));
		}
		catch(User::UserException e)
		{
			//can be book not borrowed so we ignore it
		}
		throw bookExp;
	}
	catch (User::UserException userExp)
	{
		book.returnBook();
		throw userExp;
	}
}

void LibOrganizer::returnBook(std::string userName, std::string bookTitle)
{
	User& user = userNameIndex[userName];
	Book& book = findBookPerTitle(bookTitle);
	returnBook(std::ref(user), std::ref(book));
}

void LibOrganizer::returnBook(User& user, Book& book)
{
	user.returnBook(std::ref(book));
	book.returnBook();
}

Book& LibOrganizer::buyBook(std::string title, std::string author,std::string ISBN)
{
	//check for status and existance
	Book newBook(title, author, ISBN, Book::BookStatus::available);
	if(booksISBNIndex.count(ISBN))
	{
		Book& bookWithSameISBN = booksISBNIndex[ISBN];
		if(bookWithSameISBN == newBook 
			&& bookWithSameISBN.getStatus() == Book::BookStatus::inRequest)
		{
			bookWithSameISBN.buyFromWaitingList();
			return bookWithSameISBN;
		}
		throw LibExceptions::bookISBNAlreadyExists;
	}
	if(booksTitleIndex.count(title))
		throw LibExceptions::bookTitleAlreadyExists;
	booksISBNIndex[ISBN] = newBook;
	booksTitleIndex[title] = booksISBNIndex.find(ISBN);
	return booksISBNIndex[ISBN];
}

void LibOrganizer::requestBook(std::string bookTitle, std::string author, std::string ISBN)
{
	Book newBook(bookTitle, author, ISBN, Book::BookStatus::inRequest);
	if(booksISBNIndex.count(ISBN))
	{
		Book& bookWithSameISBN = booksISBNIndex[ISBN];
		if(bookWithSameISBN == newBook)
		{
			if(bookWithSameISBN.getStatus() == Book::BookStatus::inRequest)
			{
				if(bookWithSameISBN.request()>=MAX_REQ)
				{
					buyBookFunction(bookWithSameISBN);
					return;
				}
			}
			throw LibExceptions::bookAlreadyBought;
		}
		throw LibExceptions::bookISBNAlreadyExists;
		
	}
	if(booksTitleIndex.count(bookTitle))
	{
		throw LibExceptions::bookTitleAlreadyExists;
	}
	addBook(bookTitle, author, ISBN, Book::BookStatus::inRequest);
}
