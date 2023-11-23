/*
 * Author:  Ergashev Aliyor
 * Date: 23.11.2023
 * Name:
 */
#include <iostream>
using namespace std;

// Function to check if a number is a power of two using recursion
bool isPowerOfTwo(int n) {
    // Base cases
    if (n <= 0) {
        return false;  // If n is non-positive, it's not a power of two
    } else if (n == 1) {
        return true;  // 2^0 = 1 is a power of two
    } else {
        // Keep dividing by 2 until reaching a power of two or an odd number
        return (n % 2 == 0) && isPowerOfTwo(n / 2);
    }
}

int main() {
    // Input
    int N;
    cin >> N;

    // Check if N is a power of two and print the result
    if (isPowerOfTwo(N)) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}

