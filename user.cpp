#include "user.h"
bool User::operator< (const User& rUsr)
{
	return this->name < rUsr.name;
}

bool User::operator== (const User& rUsr)
{
	return this->name == rUsr.name;
}

User::User(std::string name) : name(name)
{
	for(int i = 0; i < MAX_BOOKS; i++)
		borrowedBooks[i] = nullptr;
}

void User::borrowBook(Book& book)
{
	if(numOfBooks >= MAX_BOOKS)
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
	if(i == 10)
	{
		throw UserException::noSuchBook;
	}
	borrowedBooks[i] = &book;
	numOfBooks++;
	return;
}
void User::returnBook(Book& book)
{
	int i;
	for(i = 0; i < 10; i++)
	{
		if(borrowedBooks[i] == &book)
		{
			borrowedBooks[i] = nullptr;
			numOfBooks--;
			return;
		}
	}
}

std::string User::toString()
{
	std::string s = name + ":\n";
	for(int i = 0; i < 10; i++){
		if(borrowedBooks[i] != nullptr)
		{
			s+=borrowedBooks[i]->toString() + "\n";
		}
	}
	return s;
}
