void inputSalaries(int *salaries, int n){
    for (int i = 0; i<n; i++){
        scanf("%d", &salaries[i]);
    }
}
void displaySalaries(int *salaries, int n){
    for (int i = 0; i<n; i++){
        printf("Employee %d: %d\n", i+1, salaries[i]); 
    }
}
float calculateAverage(int *salaries, int n){
    float sum;
    for (int i = 0; i<n; i++){
        sum+=salaries[i];
    }
    float average = sum/n;
    return average;
}
int findMaxSalary(int *salaries, int n){
    int max = -99999999;
    for (int i = 0; i<n; i++){
        if (salaries[i]>max){
            max = salaries[i];
        }
    }
    return max;
}
int findMinSalary(int *salaries, int n){
    int min = 99999999;
    for (int i = 0; i<n; i++){
        if (salaries[i]<min){
            min = salaries[i];
        }
    }
    return min;
}