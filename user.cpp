#include "user.h"
bool User::operator< (const User& rUsr)
{
	return this->name <  rUsr.name;
}
User::User(std::string name) : name(name), borrowedBooks(10, nullptr), numOfBooks(0)
{
}
User::~User()
{
}
void User::borrowBook(Book* book)
{
	if(numOfBooks >= 10)
	{
		throw UserException::reachedMaxNumberOfBooks;
	}
	int i;
	for(i = 0; i < 10; i++)
	{
		if(borrowedBooks[i] == nullptr)
		{
			break;
		}
	}
	borrowedBooks[i] = book;
	numOfBooks++;
}
void User::returnBook(Book* book)
{
	int i;
	for(i = 0; i < 10; i++)
	{
		if(borrowedBooks[i] == book)
		{
			borrowedBooks[i] = nullptr;
			numOfBooks--;
			return;
		}
	}
}
