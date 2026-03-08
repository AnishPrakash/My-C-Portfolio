#include <stdio.h>
#include <ctype.h>
#include <limits.h>
#include <string.h>
int main(){
	char a[100];
	int freq[26] = {0};
	scanf("%[^\n]*c",&a);
	int l = strlen(a);
	int count = 0;
	for(int i = 0; i<l/2; i++){
		if(tolower(a[i])==tolower(a[l-1-i])){
			count++;
		}
	}
	if(count==l/2+1){
		printf("Signal Valid\n");
	}
	else{
		printf("Signal Corrupted\n");
		for(int i = 0; a[i]!='\0'; i++){
			if(isalpha(a[i])){
				freq[tolower(a[i])-'a']++;	
			}
		}
		int max = INT_MIN;
		int holder = -1;
		for(int i = 0; i<26; i++){
			if(freq[i]>max){
				max = freq[i];
				holder = i;
			}
		}
		if(holder != -1) {
            printf("Dominant Noise Character: %c (count: %d)", (holder + 'a'), max);
        } 
		else {
            printf("No letters found in noise.");
        }
    }
    return 0;
}