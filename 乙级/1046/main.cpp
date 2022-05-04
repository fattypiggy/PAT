#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int cnt1 = 0, cnt2 = 0;
    while (n--) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        int sum = a + c;
        if (b == sum && d != sum)
            ++cnt2;
        else if (b != sum && d == sum)
            ++cnt1;
    }
    cout << cnt1 << " " << cnt2;
    return 0;
}
