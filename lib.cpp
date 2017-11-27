#include"lib.h"
#include<iostream>
void LibOrganizer::defaultBuyBookFunction(Book book)
{
	cout << "please buy the following book " + book.toString() << endl;
}

LibOrganizer::LibOrganizer(std::function<void(Book)> buyBookFunction) : buyBookFunction(buyBookFunction)
{
}

void LibOrganizer::addBook(std::string title, std::string author, std::string ISBN, std::string status)
{
	Book book(title, author, ISBN, status);
	booksISBNIndex[ISBN] = book;
	booksTitleIndex[title] = booksISBNIndex[book];
}

Book LibOrganizer::findBookPerTitle(std::string title)
{
	if(!booksTitleIndex.count(title)){
		throw libExcpetions::bookNotFound;
	return booksTitleIndex[*title];
}

Book LibOrganizer::findBookPerISBN(std::string ISBN)
{
	if(!bookISBNIndex.count(ISBN))
		throw libExceptions::bookNotFound;
	return bookISBNIndex[ISBN];
}

void 
