#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main() {
    string a, b;
    cin >> a >> b;
    int s1 = a.size(), s2 = b.size();
    if (s1 > s2) // 若b比a短，需要在b的前面补0
        b = string(s1 - s2, '0') + b;
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    for (int i = 0; i < s1; ++i) {
        if (i % 2 == 0) {
            int tmp = (a[i] - '0' + b[i] - '0') % 13;
            if (tmp < 10)
                b[i] = tmp + '0';
            else if (tmp == 10)
                b[i] = 'J';
            else if (tmp == 11)
                b[i] = 'Q';
            else
                b[i] = 'K';
        } else {
            int tmp = b[i] - a[i];
            if (tmp < 0)
                b[i] = tmp + 10 + '0';
            else
                b[i] = tmp + '0';
        }
    }
    reverse(b.begin(), b.end());
    cout << b << endl;
    return 0;
}
