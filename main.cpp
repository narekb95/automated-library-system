#include<iostream>
#include"lib.h"
using namespace std;
int main(){
	LibOrganizer lib1;
	User& me = lib1.addUser("narek");
	lib1.addUser("haik");
	Book& intro = lib1.buyBook("CLRS", "thomas cormen", "123456789");
	lib1.buyBook("1985", "george..", "987654321");
	lib1.borrowBook("narek", "CLRS");
	cout << me.toString() << endl;
	cout << "___________________________\n";
	cout << intro.toString() << endl;
	cout << "is borrowed by: " << intro.getUser()->getName() << endl;
	for(int i = 0; i < 55; i++){
		cout << i << endl;
		try
		{
		lib1.borrowBook("haik", "1985");
		lib1.returnBook("haik", "1985");
		}
		catch(LibOrganizer::LibExceptions e)
		{
			if(e == LibOrganizer::LibExceptions::bookNotFound)
			{
				cout << "book doesn't exist\n";
				lib1.buyBook("1985", "george...", "987654321");
			}
		}
	}
	User& haik = lib1.findUserPerName("haik");
	cout << haik.toString();
	return 0;
}
