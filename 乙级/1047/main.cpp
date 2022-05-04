#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    map<string, int> m;
    while (n--) {
        string s;
        int g;
        cin >> s >> g;
        auto i = s.find('-');
        string t = s.substr(0, i);
        string p = s.substr(i + 1);
        m[t] += g;
    }
    int MAX = -1;
    string team;
    for (auto [t, g] : m) {
        if (g > MAX) {
            MAX = g;
            team = t;
        }
    }
    cout << team << " " << MAX;
    return 0;
}
