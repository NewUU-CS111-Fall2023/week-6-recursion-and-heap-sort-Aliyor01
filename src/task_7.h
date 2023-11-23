/*
 * Author:  Ergashev Aliyor
 * Date: 23.11.2023
 * Name:
 */
#include <iostream>
using namespace std;

int reverseDigits(int n, int reversed) {
    if (n == 0) {
        return reversed;
    } else {
        int lastDigit = n % 10;
        reversed = reversed * 10 + lastDigit;

        return reverseDigits(n / 10, reversed);
    }
}

int main() {
    int n;
    cin >> n;

    int reversed = reverseDigits(n, 0);
    cout << reversed << endl;

    return 0;
}
