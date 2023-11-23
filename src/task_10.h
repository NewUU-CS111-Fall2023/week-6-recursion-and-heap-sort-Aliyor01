/*
 * Author:  Ergashev Aliyor
 * Date: 23.11.2023
 * Name:
 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

string sortString(string s) {
    vector<pair<int, char>> vowels;

    string vowelSet = "lYmpH";

    for (int i = 0; i < s.length(); ++i) {
        if (vowelSet.find(s[i]) != string::npos) {
            vowels.emplace_back(i, s[i]);
        }
    }

    if (!vowels.empty()) {
        sort(vowels.begin(), vowels.end(), [](const pair<int, char>& a, const pair<int, char>& b) {
            return tolower(a.second) == tolower(b.second) ? a.second < b.second : tolower(a.second) < tolower(b.second);
        });

        for (const auto& vowel : vowels) {
            s[vowel.first] = vowel.second;
        }
    }

    return s;
}

int main() {
    string s = "newUzbekiStanunIverSIty";
    cout << sortString(s) << endl;

    return 0;
}

