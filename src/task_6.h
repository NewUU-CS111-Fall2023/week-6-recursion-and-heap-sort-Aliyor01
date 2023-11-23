/*
 * Author:  Ergashev Aliyor
 * Date: 23.11.2023
 * Name:
 */
#include <iostream>
#include <climits>
using namespace std;

void findSecondLargest(int& largest, int& secondLargest) {
    int num;
    cin >> num;

    if (num == 0) {
        return;
    }

    if (num > largest) {
        secondLargest = largest;
        largest = num;
    } else if (num > secondLargest && num != largest) {
        secondLargest = num;
    }

    findSecondLargest(largest, secondLargest);
}

int main() {
    int largest = INT_MIN;
    int secondLargest = INT_MIN;

    findSecondLargest(largest, secondLargest);

    if (secondLargest != INT_MIN) {
        cout << secondLargest << endl;
    } else {
        cout << "There is no second largest element." << endl;
    }

    return 0;
}
