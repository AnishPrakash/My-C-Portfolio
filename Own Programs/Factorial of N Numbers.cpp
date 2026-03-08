#include <iostream>
using namespace std;
int main(){
	cout << "Enter N : ";
	long long x;
	cin >> x;
	int ans = 1;
	for (int i = 1; i<=x; i++){
		ans *= i;
	}
	cout << "Factorial of " << x << " is : " << ans;
	return 0;
}