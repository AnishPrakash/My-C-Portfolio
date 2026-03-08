// You are using GCC
int gcd(int b, int a) {
    while(a!=0){
        int temp = a;
        a=b%a;
        b=temp;
    }
    return b;
}