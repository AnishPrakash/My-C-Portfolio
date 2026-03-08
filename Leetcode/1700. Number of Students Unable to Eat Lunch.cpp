int countStudents(int* students, int studentsSize, int* sandwiches, int sandwichesSize) {
    int counts[2] = {0};
    for (int i = 0; i < studentsSize; i++) {
        counts[students[i]]++;
    }
    for (int i = 0; i < sandwichesSize; i++) {
        if (counts[sandwiches[i]] > 0) {
            counts[sandwiches[i]]--;
        } else {
            return sandwichesSize - i;
        }
    }
    return 0;
}