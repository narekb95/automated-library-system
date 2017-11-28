#include "user.h"
#include<iostream>
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
	numOfBooks = 0;
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
    int freeIndex = -1;
	for(i = 0; i < 10; i++)
	{
		if(borrowedBooks[i] == nullptr)
		{
            freeIndex = i;
		}
        if(borrowedBooks[i] == &book)
        {
            throw UserException::bookAlreadyBorrowed;
        }
	}
	borrowedBooks[freeIndex] = &book;
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
            break;
		}
	}
    if(i == 10)
    {
        throw UserException::noSuchBook;
    }
    borrowedBooks[i] = nullptr;
    numOfBooks--;
    return;
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

std::string User::getName()
{
    return this->name;
}
