#include "user.h"
bool User::operator== (const User& rUsr)
{
	return this->globalUniqueUserId == rUsr.globalUniqueUserId;
}
bool User::operator< (const User& rUsr)
{
	return this->globalUniqueUserId <  rUsr.globalUniqueUserId;
}
User::User(std::string name) : name(name), borrowedBooks(10, ""), numOfBooks(0)
{
	this->globalUniqueUserId = generateId();
	usedIds[globalUniqueUserId] = this;
}
User::~User()
{
	usedIds.erase(this->globalUniqueUserId);
}
std::string User::generateId()
{
	srand(time(0));
	std::string s;
	do
	{
		s = "";
		for(int i = 0; i < 10; i++)
		{
			s += (rand()%10)+'0';
		}
	}while(!usedIds.count(s));
	return s;
}
bool User::borrowBook(Book* book)
{
	if(numOfBooks >= 10)
	{
		return false;
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
	return true;
}
bool User::returnBook(Book* book)
{
	int i;
	for(i = 0; i < 10; i++)
	{
		if(borrowedBooks[i] == book)
		{
			borrowedBooks[i] = nullptr;
			numOfBooks--;
			return true;
		}
	}
	return false;
}
