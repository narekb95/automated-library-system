#include "book.h"

Book::Book(std::string title, std::string author, std::string ISBN, BookStatus status) : title(title), author(author), ISBN(ISBN), status(status)
{
	if(status == BookStatus::inRequest)
	{
		numOfRequests = 1;
	}
	numOfUses = 0;
}

//todo: add user to requesting list and not accept two from the same user

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

bool Book::operator==(const Book& rhs) const
{
	return this->title == rhs.title
		&& this->ISBN == rhs.ISBN
		&& this->author == rhs.author;
}

std::string Book::toString()
{
	return this->title + " " + this->author + " " + this->ISBN;
}

User* Book::getUser()
{
    if(status !=  BookStatus::borrowed)
    {
        throw BookException::notBorrowed;
    }
	return this->user;
}

std::string Book::getTitle() const
{
	return this->title;
}

std::string Book::getISBN() const
{
	return this->ISBN;
}

std::string Book::getAuthor() const
{
    return this->author;
}

void Book::buyFromWaitingList()
{
	if(this->status != BookStatus::inRequest)
		throw BookException::notInRequest;
	this->status = BookStatus::available;
}

Book::BookStatus Book::getStatus() const
{
	return this->status;
}

int Book::request(User* user)
{
    if(requestMaker.count(user))
        throw BookException::hasBeenRequestedFromThisUser;
    requestMaker[user] = true;
    this->numberOfRequests++;
    return this->numberOfRequests;
}
