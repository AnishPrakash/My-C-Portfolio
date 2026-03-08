#include <stdio.h>
int main(){
	char a;
	do{
		scanf("%c",&a);
		printf("\n");
		if(a=='-'){
			int n1, n2;
			scanf("%d %d",&n1,&n2);
			int ans = n1-n2;
			printf("%d",ans);
		}
		else if(a=='*'){
			int n1,n2;
			scanf("%d %d",&n1,&n2);
			int p1 = 1, p2 = 1;
			while(n1!=0){
				int r = n1%10;
				p1*=r;
				n1/=10;
			}
			while(n2!=0){
				int r = n2%10;
				p2*=r;
				n2/=10;
			}
			printf("%d",p1+p2);
		}
		else if(a=='@'){
			int n1, n2;
			scanf("%d %d",&n1,&n2);
			int ans = n1+n2;
			int sum = 0;
			while(ans!=0){
				int r = ans%10;
				sum+=r;
				ans/=10;
			}
			printf("%d",ans);
		}
		else if(a=='0'){
			printf("Exiting Calculator");
			break;
		}
		else{
			printf("Invalid Input");
		}
	}
	while(1);
	return 0;
}