#include<iostream>
#include"lib.h"
using namespace std;
int main(){
	LibOrganizer lib1;
	User& me = lib1.addUser("narek");
	cout << 1 << endl;
	lib1.addUser("haik");
	cout << 2 << endl;
	Book& intro = lib1.buyBook("CLRS", "thomas cormen", "123456789");
	cout << 3 << endl;
	lib1.buyBook("1985", "george..", "987654321");
	cout << 4 << endl;
	lib1.borrowBook("narek", "CLRS");
	cout << 5 << endl;
	cout << me.toString() << endl;
	cout << 6 << endl;
	cout << "___________________________\n";
	cout << 7 << endl;
	cout << intro.toString() << endl;
	cout << 8 << endl;
	cout << "is owned by:\n" << intro.getUser()->toString() << endl;
	cout << 9 << endl;
	return 0;
}
