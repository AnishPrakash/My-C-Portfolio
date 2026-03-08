#include <stdio.h>
struct Student{
	char name[100];
	int marks;
};
void display(struct Student *ptr, int n){
	for (int i = 0; i<n; i++){
		printf("Name: %s, Marks: %d\n",(ptr+i)->name,(ptr+i)->marks);
	}
}
int main(){
	int n;
	scanf("%d",&n);
	struct Student s[n];
	for (int i = 0; i<n; i++){
		scanf("%s",s[i].name);
		scanf("%d",&s[i].marks);
	}
	display(s,n);
	return 0;
}