#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<vector<string>> v(3, vector<string>());
    vector<string> s(3);
    int n = 3;
    for (int i = 0; i < n; ++i) {
        getline(cin, s[i]);
        auto index = s[i].find("[");
        while (index != s[i].npos) {
            auto end = s[i].find("]", index);
            v[i].push_back(s[i].substr(index + 1, end - index - 1));
            index = s[i].find("[", end);
        }
    }
    int num;
    cin >> num;
    while (num--) {
        int a, b, c, d, e;
        cin >> a >> b >> c >> d >> e;
        if (a > v[0].size() || e > v[0].size() || b > v[1].size() || d > v[1].size() || c > v[2].size()
          || a <= 0 || b <= 0 || c <= 0 || d <= 0 || e <= 0)
            cout << "Are you kidding me? @\\/@" << endl;
        else
            cout << v[0][a-1] << '(' << v[1][b-1] << v[2][c-1] << v[1][d-1] << ')' << v[0][e-1] << endl;
    }
    return 0;
}
