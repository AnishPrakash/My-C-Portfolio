int convertTime(char* current, char* correct) {
    int currMins = (current[0] - '0') * 600 + (current[1] - '0') * 60 + (current[3] - '0') * 10 + (current[4] - '0');
    int corrMins = (correct[0] - '0') * 600 + (correct[1] - '0') * 60 + (correct[3] - '0') * 10 + (correct[4] - '0');
    int diff = corrMins - currMins;
    
    int ops = 0;
    ops += diff / 60; diff %= 60;
    ops += diff / 15; diff %= 15;
    ops += diff / 5;  diff %= 5;
    ops += diff;      
    return ops;
}