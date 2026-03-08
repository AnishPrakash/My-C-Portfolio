#include <stdio.h>
struct Student{
	int RollNo;
	char Name[100];
	int Marks;
};
void updateMarks(struct Student * s){
	s->Marks+=5;
}
int main(){
	struct Student s[3];
	for (int i = 0; i<3; i++){
		scanf("%d %s %d",&s[i].RollNo, s[i].Name, &s[i].Marks);
	}
	for (int i = 0; i<3; i++){
		updateMarks(&s[i]);
	}
	struct Student * p = s;
	for (int i = 0; i<3; i++){
		printf("%d - %s - %d\n",p->RollNo, p->Name, p->Marks);
		p++;
	}
	return 0;
}