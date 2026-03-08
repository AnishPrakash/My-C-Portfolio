#include <stdio.h>
int main(){
	int n;
	scanf("%d",&n);
	int sum = 0;
	while(n!=0){
		int r = n%10;
		sum+=r;
		n/=10;
	}
	int ans = 0;
	if (sum>=10){
		while(sum!=0){
			int r = sum%10;
			ans+=r;
			sum/=10;
		}
	}
	printf("%d",ans);
	return 0;
}