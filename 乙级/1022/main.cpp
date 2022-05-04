#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main() {
    int a, b, c, d;
    cin >> a >> b >> c;
    d = a + b;
    string ans;
    while (d) {
        ans += to_string(d % c);
        d /= c;
    }
    reverse(ans.begin(), ans.end());
    cout << (ans == "" ? "0" : ans) << endl;
    return 0;
}
