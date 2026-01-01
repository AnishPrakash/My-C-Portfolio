// Given an array of positive integers where every element 
//appears exactly twice except for one element which 
//appears an odd number of times, 
//write a C program to find that single 
//odd-occurring element using bitwise operators 
//(Time Complexity: O(N), Space Complexity: O(1)).
//2 Approaches. 2 For Loops for O(N2) and Bitwise XOR for O(N)

#include <stdio.h>
int main(){
	int n;
	printf("Provide the size of the array!\n");
	scanf("%d",&n);
	int arr[n];
	printf("Provide elements for the array!\n");
	for (int i = 0; i<n; i++){
		scanf("%d",&arr[i]);
	}
	int result = 0;
	for (int i = 0; i<n; i++){
		result = result ^ arr[i];
	}
	printf("The element occuring odd number of times is %d",result);
	return 0;
}