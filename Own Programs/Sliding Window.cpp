#include <stdio.h>
int main(){
	int arr[7] = {34,145,67,1004,88,456,2034};
	int window_size = 3;
	int fav_number = 8;
	for (int i = 0; i<5; i++){
		int arr1[window_size];
		arr1[0] = arr[i];
		arr1[1] = arr[i+1];
		arr1[2] = arr[i+2];
		int max_ones = -1, max_tens = -1, max_hundreds = -1, max_thousands = -1;
		for (int j = 0; j<3; j++){
			int temp = arr1[j];
			int o = 0, t = 0, h = 0, th = 0;
			o = temp%10;
			temp/=10;
			t = temp%10;
			temp/=10;
			h = temp%10;
			temp/=10;
			th = temp%10;
			if (o>max_ones)
				max_ones = o;
			if (t>max_tens)
				max_tens = t;
			if (h>max_hundreds)
				max_hundreds = h;
			if (th>max_thousands)
				max_thousands = th;
		}
		int ans = 1000*max_thousands + 100*max_hundreds + 10*max_tens + 1*max_ones;
		printf("{%d %d %d} %d\n",arr[i],arr[i+1],arr[i+2],ans);
	}
	for (int i = 0; i<5; i++){
		int arr1[window_size];
		arr1[0] = arr[i];
		arr1[1] = arr[i+1];
		arr1[2] = arr[i+2];
		int max_ones = -1, max_tens = -1, max_hundreds = -1, max_thousands = -1;
		for (int j = 0; j<3; j++){
			int temp = arr1[j];
			int o = 0, t = 0, h = 0, th = 0;
			o = temp%10;
			temp/=10;
			t = temp%10;
			temp/=10;
			h = temp%10;
			temp/=10;
			th = temp%10;
			if (o>max_ones)
				max_ones = o;
			if (t>max_tens)
				max_tens = t;
			if (h>max_hundreds)
				max_hundreds = h;
			if (th>max_thousands)
				max_thousands = th;
		}
		if (max_ones == 8 || max_tens == 8 || max_hundreds == 8 || max_thousands == 8){
			printf("{%d %d %d} is a valid subarray\n",arr[i],arr[i+1],arr[i+2]);
		}
		else{
			printf("{%d %d %d} is not a valid subarray\n",arr[i],arr[i+1],arr[i+2]);
		}
	}
	return 0;
}