#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main() {
    string s;
    getline(cin, s);
    int sum = 0;
    for (const auto &c : s) {
        if (isalpha(c)) {
            if (isupper(c))
                sum += c - 'A' + 1;
            else
                sum += c - 'a' + 1;
        }
    }
    int one = 0, zero = 0;
    while (sum) {
        if (sum % 2 == 1)
            ++one;
        else
            ++zero;
        sum /= 2;
    }
    cout << zero << " " << one << endl;
    return 0;
}
