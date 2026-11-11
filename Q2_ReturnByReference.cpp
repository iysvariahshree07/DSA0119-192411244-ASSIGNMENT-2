#include <iostream>
using namespace std;

int& highest(int marks[], int n) {
    int maxIndex = 0;
    for (int i = 1; i < n; i++) {
        if (marks[i] > marks[maxIndex]) {
            maxIndex = i;
        }
    }
    return marks[maxIndex];
}

int main() {
    int marks[5] = {75, 80, 95, 85, 70};

    cout << "Highest mark: " << highest(marks, 5) << '\n';
    highest(marks, 5) += 2;
    cout << "After moderation: " << highest(marks, 5) << '\n';

    return 0;
}