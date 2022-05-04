#include <iostream>
#include <bits/stdc++.h>
using namespace std;
const vector<string> low = {"tret", "jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec"};
const vector<string> high = {"","tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou"};
string toMars(int n) {
    if (n < 13)
        return low[n];
    else
        return high[n / 13] + (n % 13 == 0 ? "" : " " + low[n % 13]);
}
int toEarth(string s) {
    auto index = s.find(' ');
    if (index == s.npos) {
        for (int i = 0; i < low.size(); ++i) {
            if (low[i] == s) {
                return i;
            }
        }
        for (int i = 0; i < high.size(); ++i) {
            if (high[i] == s) {
                return i * 13;
            }
        }
    } else {
        string h = s.substr(0, index);
        string l = s.substr(index + 1);
        int ans = 0;
        for (int i = 0; i < high.size(); ++i) {
            if (high[i] == h) {
                ans += i * 13;
                break;
            }
        }
        for (int i = 0; i < low.size(); ++i) {
            if (low[i] == l) {
                ans += i;
                return ans;
            }
        }
    }
}

string convert(string basicString) {
    if (isdigit(basicString[0]))
        return toMars(stoi(basicString));
    else
        return to_string(toEarth(basicString));
}

int main() {
    int N;
    cin >> N;
    getchar();
    while (N--) {
        string s;
        getline(cin, s);
        cout << convert(s) << endl;
    }
    return 0;
}
