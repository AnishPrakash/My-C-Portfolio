#include <stdio.h>
int count_s(char*s){
	int count = 0;
	if (*(s)=='\0'||*(s)=='\n')
		return 0;
	else{
		return 1+count_s(s+1);
	}
}
int main(){
	char s[100];
	fgets(s,sizeof(s),stdin);
	int ans = count_s(s);
	printf("%d",ans);
	return 0;
}