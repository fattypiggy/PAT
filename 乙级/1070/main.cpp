#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    vector<double> v(n);
    for (int i = 0; i < n; ++i)
        cin >> v[i];
    sort(v.begin(), v.end(), greater<double>());
    while (v.size() > 1) {
        auto b1 = v.back();
        v.pop_back();
        v.back() = v.back() / 2 + b1 / 2;
    }
    cout << (int)v[0] << endl;
    return 0;
}
