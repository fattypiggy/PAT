#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
    string str;
    int n;
    cin >> str >> n;
    string ans("");
    int reminder = 0;
    for (const auto &c : str) {
        int tmp = reminder * 10 + c - '0';
        ans += to_string(tmp / n);
        reminder = tmp % n;
    }
    cout << (ans.size() > 1 && ans[0] == '0' ? ans.substr(1) : ans) << " " << reminder << endl;
    return 0;
}

