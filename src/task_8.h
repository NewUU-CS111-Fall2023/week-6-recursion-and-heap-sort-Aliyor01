/*
 * Author:  Ergashev Aliyor
 * Date: 23.11.2023
 * Name:
 */
#include <iostream>
#include <string>

#define max(a, b) ((a) > (b) ? (a) : (b))

using namespace std;

string add(const string& lhs, const string& rhs) {
    int length = max(lhs.size(), rhs.size());
    int carry = 0;
    int sum_col;
    string result;

    string temp_lhs = lhs;
    string temp_rhs = rhs;

    while (temp_lhs.size() < length)
        temp_lhs.insert(0, "0");

    while (temp_rhs.size() < length)
        temp_rhs.insert(0, "0");

    for (int i = length - 1; i >= 0; i--) {
        sum_col = (temp_lhs[i] - '0') + (temp_rhs[i] - '0') + carry;
        carry = sum_col / 10;
        result.insert(0, to_string(sum_col % 10));
    }

    if (carry)
        result.insert(0, to_string(carry));

    return result.erase(0, min(result.find_first_not_of('0'), result.size() - 1));
}

string subtract(const string& lhs, const string& rhs) {
    int length = max(lhs.size(), rhs.size());
    int diff;
    string result;

    string temp_lhs = lhs;
    string temp_rhs = rhs;

    while (temp_lhs.size() < length)
        temp_lhs.insert(0, "0");

    while (temp_rhs.size() < length)
        temp_rhs.insert(0, "0");

    for (int i = length - 1; i >= 0; i--) {
        diff = (temp_lhs[i] - '0') - (temp_rhs[i] - '0');
        if (diff >= 0)
            result.insert(0, to_string(diff));
        else {
            int j = i - 1;
            while (j >= 0) {
                temp_lhs[j] = ((temp_lhs[j] - '0') - 1) % 10 + '0';
                if (temp_lhs[j] != '9')
                    break;
                else
                    j--;
            }
            result.insert(0, to_string(diff + 10));
        }
    }

    return result.erase(0, min(result.find_first_not_of('0'), result.size() - 1));
}

string multiply(const string& lhs, const string& rhs) {
    int length = max(lhs.size(), rhs.size());

    string temp_lhs = lhs;
    string temp_rhs = rhs;

    while (temp_lhs.size() < length)
        temp_lhs.insert(0, "0");

    while (temp_rhs.size() < length)
        temp_rhs.insert(0, "0");

    if (length == 1)
        return to_string((temp_lhs[0] - '0') * (temp_rhs[0] - '0'));

    string lhs0 = temp_lhs.substr(0, length / 2);
    string lhs1 = temp_lhs.substr(length / 2, length - length / 2);
    string rhs0 = temp_rhs.substr(0, length / 2);
    string rhs1 = temp_rhs.substr(length / 2, length - length / 2);

    string p0 = multiply(lhs0, rhs0);
    string p1 = multiply(lhs1, rhs1);
    string p2 = multiply(add(lhs0, lhs1), add(rhs0, rhs1));
    string p3 = subtract(p2, add(p0, p1));

    for (int i = 0; i < 2 * (length - length / 2); i++)
        p0.append("0");
    for (int i = 0; i < length - length / 2; i++)
        p3.append("0");

    string result = add(add(p0, p1), p3);

    return result.erase(0, min(result.find_first_not_of('0'), result.size() - 1));
}

int main() {
    string s1, s2;
    cin >> s1 >> s2;
    cout << multiply(s1, s2) << endl;
    return 0;
}

