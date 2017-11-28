#include<iostream>
#include<functional>
#include"lib.h"
using namespace std;
void bookMyOwnBookBuyer(LibOrganizer* lib, Book book)
{
    cout << "I am using own handler to buy a book";
    lib->buyBook(book.getTitle(), book.getAuthor(), book.getISBN());
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
		}
        lib1.returnBook("haik", "1985");
	}
    cout <<"End of testcase 1..\n\n\n\n";
    
    LibOrganizer *lib2;
    auto binder = std::bind(bookMyOwnBookBuyer, lib2, placeholders::_1);
    lib2 = new LibOrganizer(binder);
    cout << lib2->buyBook("hamlet", "shakespere", "555555").toString() << endl;
    cout << lib2->addUser("eva").toString() << endl;
    for(int i = 0; i < 55; i++)
    {
        try
        {
            lib2->borrowBook("eva", "hamlet");
        }
        catch(LibOrganizer::LibExceptions e)
        {
            if(e == LibOrganizer::LibExceptions::bookNotFound)
            {
                //should never be called
                cout <<"The book doesn't exist\n";
            }
        }
        lib2->returnBook("eva", "hamlet");
    }
    cout << endl;
    delete lib2;
	return 0;
}
