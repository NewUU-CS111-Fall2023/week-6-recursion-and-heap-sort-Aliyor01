/*
 * Author:  Ergashev Aliyor
 * Date: 23.11.2023
 * Name:
 */
#include <iostream>
#include <cmath>
using namespace std;

bool isPrime(int n, int divisor = 2) {
    if (n < 2) {
        return false;  // Numbers less than 2 are not prime
    } else if (divisor > sqrt(n)) {
        return true;  // If no divisor found, it's a prime number
    } else if (n % divisor == 0) {
        return false;  // If n is divisible by the current divisor, it's not prime
    } else {
        return isPrime(n, divisor + 1);  // Check the next divisor
    }
}

int main() {
    int n;
    cin >> n;

    if (isPrime(n)) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}

