#include<iostream>
#include<functional>
#include"lib.h"
using namespace std;
void bookMyOwnBookBuyer(LibOrganizer** lib, Book book)
{
    cout << "I am using own handler to buy a book";
    (*lib)->buyBook(book.getTitle(), book.getAuthor(), book.getISBN());
}
void testCallback(Book book)
{
    cout << "call back testing function to book " << book.toString() << endl;
}
int main(){
	LibOrganizer lib1;
	User& me = lib1.addUser("narek");
	lib1.addUser("haik");
    User& haik = lib1.findUserPerName("haik");
    
	Book& intro = lib1.buyBook("CLRS", "thomas cormen", "123456789");
	lib1.buyBook("1985", "george..", "987654321");
	lib1.borrowBook("narek", "CLRS");
    lib1.borrowBook("narek", "1985");
	cout << me.toString() << endl << endl;
    lib1.returnBook("narek", "1985");
    cout << intro.toString() << endl << endl;
	cout << "is borrowed by: " << intro.getUser()->getName() << endl;
    
	for(int i = 0; i < 55; i++){
		try
		{
            lib1.borrowBook("haik", "1985");
		}
		catch(LibOrganizer::LibExceptions e)
		{
			if(e == LibOrganizer::LibExceptions::bookNotFound)
			{
                cout << "returned " << i << " times\n";
				cout <<"The book doesn't exist\n";
				lib1.buyBook("1985", "george...", "987654321");
                continue;
			}
            else
            {
                throw e;
            }
		}
        lib1.returnBook("haik", "1985");
	}
    cout <<"End of testcase 1..\n\n\n\n";
    
    
    LibOrganizer lib2(testCallback);
    lib2.addUser("beshara");
    lib2.buyBook("learn english", "toefl", "333333");
    for(int i = 0; i < 55; i++)
    {
        try
        {
            lib2.borrowBook("beshara", "learn english");
        }
        catch (LibOrganizer::LibExceptions e) {
            if(e == LibOrganizer::LibExceptions::bookNotFound)
            {
                lib2.buyBook("learn english", "toefl", "333333");
                continue;
            }
            else
            {
                throw e;
            }
        }
        lib2.returnBook("beshara", "learn english");
    }
    cout <<"End of testcase 2..\n\n\n\n";
    
    
    
    LibOrganizer *lib3;
    std::function<void(Book)> binderTest = std::bind(bookMyOwnBookBuyer, &(lib3), placeholders::_1);
    //std::function<void(Book)> binderTest =testCallback;
    lib3 = new LibOrganizer(binderTest);
    cout << lib3->buyBook("hamlet", "shakespere", "555555").toString() << endl;
    cout << lib3->addUser("eva").toString() << endl;
    for(int i = 0; i < 55; i++)
    {
        try
        {
            lib3->borrowBook("eva", "hamlet");
        }
        catch(LibOrganizer::LibExceptions e)
        {
            if(e == LibOrganizer::LibExceptions::bookNotFound)
            {
                cout <<"The book doesn't exist\n";
                lib3->buyBook("hamlet", "shakespere", "555555").toString();
                continue;
            }
            else
                throw e;
        }
        lib3->returnBook("eva", "hamlet");
    }
    cout << endl;
    delete lib3;
	return 0;
}
