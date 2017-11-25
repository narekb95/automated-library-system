#include "book.h"

Book::Book(std::string title, std::string author, std::string ISBN) : name(name), author(author), ISBN(ISBN)
{
}

void Book::request()
{
	this->numberOfRequests++;
}

std::string Book::getTitle()
{
	return this->title;
}

bool Book::isAvailable()
{
	return  borrowedCopies < totalCopies;
}
bool Book::borrow(User* user)
{
	if(isAvailable())
	{
		borrowedCopies++;	
		addUser(user);
		return true;
	}
	return false;
}
void Book::addUser(User* user)
{
}
