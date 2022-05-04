#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    sort(v.begin(), v.end(), greater<int>());
    int e = 0;
    for (int i = 0; i < n; ++i) {
        if (v[i] > i + 1)
            ++e;
        else
            break;
    }
    cout << e;
    return 0;
}
