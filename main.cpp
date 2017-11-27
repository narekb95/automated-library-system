#include<iostream>
#include"lib.h"
using namespace std;
int main(){
	LibOrganizer lib1;
	User me = lib1.addUser("narek");
	lib1.addUser("haik");
	Book intro = lib1.buyBook("CLRS", "thomas cormen", "123456789");
	lib1.buyBook("1985", "george..", "987654321");
	lib1.borrowBook("narek", "CLRS");
	cout << me.toString() << endl;
	cout << "___________________________\n";
	cout << intro.toString() << endl;
	return 0;
}
