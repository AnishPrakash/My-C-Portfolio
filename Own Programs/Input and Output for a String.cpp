#include <iostream>
using namespace std;
int main(){
	int x;
	string name;
	string name2;
	cout << "Enter your name! ";
	cin >> name; //Reads till first whitespace
	cin.ignore(); //it clears the pressed enter key or the input buffer
	getline(cin, name2); //Reads full sentence but the problem is we need to clear the previosu stored "buffer enter key"
	cout << "Hello " << name << "! Welcome to C++\n";
	cout << "Hello " << name2 << "! Welcome to C++\n";
	return 0;
}