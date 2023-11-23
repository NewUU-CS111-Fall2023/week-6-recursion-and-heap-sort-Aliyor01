/*
 * Author:  Ergashev Aliyor
 * Date: 23.11.2023
 * Name:
 */
#include <iostream>
using namespace std;

void printSequence(int start, int end, int step) {
    if (start == end) {
        cout << start << " ";
        return;
    }
    cout << start << " ";
    printSequence(start + step, end, step);
}

int main() {
    int x, y;
    cin >> x >> y;

    if (x > y) {
        printSequence(x, y, -1); // Print in descending order
    } else {
        printSequence(x, y, 1);  // Print in ascending order
    }

    return 0;
}
