/*
 * Author:  Ergashev Aliyor
 * Date: 23.11.2023
 * Name:
 */
#include <iostream>
#include <cstring>
using namespace std;

bool isPalindrome(const char* word, int start, int end) {
    if (start >= end) {
        return true;  // Empty string or single-character string is a palindrome
    } else if (word[start] != word[end]) {
        return false;  // Characters at the corresponding positions do not match
    } else {
        return isPalindrome(word, start + 1, end - 1);  // Check the next pair of characters
    }
}

int main() {
    char word[100];
    cin >> word;

    if (isPalindrome(word, 0, strlen(word) - 1)) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}

