#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    unsigned long long s = 0l;
    for (int i = 0; i < n; ++i) {
        double tmp;
        cin >> tmp;
        long long ll = tmp * 1000;
        s += ll * (n - i) * (i + 1);
    }
    double sum = s / 1000.0;
    printf("%.2f", sum);
    return 0;
}
