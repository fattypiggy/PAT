#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
    const vector<string> day{"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};
    vector<string> v(4);
    for (int i = 0; i < 4; ++i) {
        cin >> v[i];
    }
    bool first = false;
    for (int i = 0; i < v[0].size(); ++i) {
        if (v[0][i] == v[1][i]) {
            if (!first && v[0][i] >= 'A' && v[0][i] <= 'G') {
                first = true;
                cout << day[v[0][i] - 'A'] << " ";
            } else if (first && isdigit(v[0][i])) {
                cout << "0" << v[0][i] << ":";
                break;
            } else if (first && v[0][i] >= 'A' && v[0][i] <= 'N') {
                cout << v[0][i] - 'A' + 10 << ":";
                break;
            }
        }
    }
    for (int i = 0; i < v[2].size(); ++i) {
        if (isalpha(v[2][i]) && v[2][i] == v[3][i]) {
            cout << (i > 9 ? to_string(i) : '0' + to_string(i)) << endl;
            break;
        }
    }
    return 0;
}