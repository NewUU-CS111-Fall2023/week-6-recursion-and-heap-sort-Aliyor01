/*
 * Author:  Ergashev Aliyor
 * Date: 23.11.2023
 * Name:
 */
#include <iostream>
using namespace std;

// Function to calculate the sum of digits using recursion
int sumOfDigits(int n) {
    // Base case: if n becomes zero, return 0
    if (n == 0) {
        return 0;
    } else {
        // Extract the last digit and add it to the sum
        int lastDigit = n % 10;
        return lastDigit + sumOfDigits(n / 10);
    }
}

int main() {
    // Input
    int N;
    cin >> N;

    // Calculate the sum of digits and print the result
    cout << sumOfDigits(N) << endl;

    return 0;
}

