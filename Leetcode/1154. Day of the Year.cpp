int dayOfYear(char * date) {
    int y = atoi(date);
    int m = atoi(date + 5);
    int d = atoi(date + 8);
    
    int days[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    
    if ((y % 4 == 0 && y % 100 != 0) || (y % 400 == 0)) {
        days[2] = 29;
    }
    
    int total = 0;
    for (int i = 1; i < m; i++) {
        total += days[i];
    }
    
    return total + d;
}