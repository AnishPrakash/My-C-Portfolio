#include <iostream>
using namespace std;
int main(){
	cout << "Enter N: ";
	int x;
	cin >> x;
	int total = 0;
	for (int i = 1; i<=x; i++){
		total+=i;
	}
	cout << "Total : " << total;
	return 0;
}