#include "book.h"

Book::Book(std::string title, std::string author, std::string ISBN, BookStatus status) : title(title), author(author), ISBN(ISBN), status(status)
{
}

//todo: add user to requesting list and not accept two from the same user
void Book::request(std::string user)
{
	this->numberOfRequests++;
}

std::string Book::getTitle()
{
	return this->title;
}

bool Book::isAvailable()
{
	return this->status == BookStatus::available;
}

void Book::borrow(User* user)
{
	if(!isAvailable())
	{
		throw BookException::notAvailable;
	}
	this->user = user;
	this->status = BookStatus::borrowed;
	numOfUses++;
	
}

int Book::returnBook()
{
	this->status = BookStatus::available;
	return numOfUses;
}

bool Book::operator<(const Book& rhs) const 
{
	return this->title < rhs.title;
}

std::string Book::toString()
{
	return this->title + " " + this->author + " " + this->ISBN;
}
