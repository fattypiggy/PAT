#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main() {
    double r1, p1, r2, p2;
    cin >> r1 >> p1 >> r2 >> p2;
    double r = r1 * cos(p1) * r2 * cos(p2) - r1 * sin(p1) * r2 * sin(p2);
    double i = r1 * cos(p1) * r2 * sin(p2) + r1 * sin(p1) * r2 * cos(p2);
    const double magic = 0.0001; // double有个精度问题
    if (r + magic >= 0 && r < 0)
        printf("0.00");
    else
        printf("%.2f", r);
    if (i >= 0)
        printf("+%.2fi\n", i);
    else if (i + magic >= 0 && i < 0)
        printf("+0.00i\n");
    else
        printf("%.2fi\n", i);
    return 0;
}

