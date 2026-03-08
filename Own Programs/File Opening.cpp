#include <stdio.h>
int main(){
	FILE *fp;
	fp = fopen("Anish.txt","w");
	char text[10];
	fscanf(fp,"%s",text);
	fprintf(fp,"%s",text);
	fclose(fp);
	return 0;
}