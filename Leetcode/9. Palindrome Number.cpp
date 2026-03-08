bool isPalindrome(int x) {
    if (x<0){
        return false;
    }
    else{
        long long rev = 0,temp = x;
        while (temp!=0){
            int r = temp%10;
            rev = (10*rev)+r;
            temp/=10;
        }
        if (rev == x){
            return true;
        }
        else{
            return false;
        }
    }
}