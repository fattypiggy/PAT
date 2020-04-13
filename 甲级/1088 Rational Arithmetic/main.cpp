// runtime: 4ms
// space: 384K
// https://pintia.cn/problem-sets/994805342720868352/problems/994805378443755520
// 虽然是20分的题目，但是想得满分，还是要仔细做题的。
#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;
long long GCD(long long a, long long b) {
    if (b == 0)
        return a;
    else {
        return GCD(b, a % b);
    }
}

// 约分
string Approximate(long long a, long long b) {
    string ans;
    if (b == 0)
        return "Inf";
    if (a == 0)
        return "0";

    int num = 0;
    bool flag = false;
    if (a < 0) num++;
    if (b < 0) num++;

    if (num % 2 == 1) flag = true;

    if (flag) ans.append("(-");

    a = abs(a), b = abs(b);

    long long gcd = GCD(a, b);

    long long integer = a / b;
    long long remainder = a % b;
    if (integer != 0) {
        ans.append(to_string(integer));
    }

    if (remainder == 0) {
        if (flag) ans.append(")");
        return ans;
    }

    if (integer != 0) {
        ans.append(" ");
    }
    a = a / gcd;
    b = b / gcd;
    ans.append(to_string(a - integer * b)).append("/").append(to_string(b));
    if (flag) ans.append(")");
    return ans;
}

int main() {
    long long n1, d1, n2, d2;
    scanf("%lld/%lld %lld/%lld", &n1, &d1, &n2, &d2);

    cout << Approximate(n1, d1) + " + " + Approximate(n2, d2) + " = " << Approximate(n1 * d2 + n2 * d1, d1 * d2) << endl;
    cout << Approximate(n1, d1) + " - " + Approximate(n2, d2) + " = " << Approximate(n1 * d2 - n2 * d1, d1 * d2) << endl;
    cout << Approximate(n1, d1) + " * " + Approximate(n2, d2) + " = " << Approximate(n1 * n2, d1 * d2) << endl;
    cout << Approximate(n1, d1) + " / " + Approximate(n2, d2) + " = " << Approximate(n1 * d2, d1 * n2) << endl;

    return 0;
}

