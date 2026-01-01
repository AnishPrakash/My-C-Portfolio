#include <stdio.h>
int main(){
	char name[50], gender;
	int age;
	scanf("%s\n%d\n%c",&name,&age,&gender);
	if (gender == 'f' || age < 12){
		printf("concession");
	}
	else {
		printf("no concession");
	}
	return 0;
}