int divide(int dividend, int divisor) {
    if(dividend==INT_MIN && divisor==-1) return INT_MAX;
    
    long a = labs(dividend);
    long b = labs(divisor);
    long res=0;
    
    while(a>=b){
        long temp=b, multiple=1;
        while(a >= (temp<<1)){
            temp <<=1;
            multiple <<=1;
        }
        a -= temp;
        res += multiple;
    }
    
    return ((dividend<0)^(divisor<0)) ? -res : res;
}
