int countMonobit(int n) {
    if (n == 0) return 1;
    int count = 2;
    int p = 0;
    int j = 2;
    for(int i = 2; i<=n; i = i+pow(2,p)){
        if(i==pow(2,j)-1){
            j++;
            count++;
            p++;
        }
    }
    return count;
}