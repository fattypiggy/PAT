#include <iostream>
#include <bits/stdc++.h>
using namespace std;
bool check(const string s, double &ans) {
    int isDouble = -1;
    for (int i = 0; i < s.size(); ++i) {
        if (isalpha(s[i]))
            return false;
        else if (s[i] == '.' && isDouble == -1) {
            isDouble = i;
            if (s.size() - i > 3)
                return false;
        } else if (s[i] == '.' && isDouble != -1) {
            return false;
        } else if (s[i] == '.' && i == 0)
            return false;
    }
    ans = stod(s);
    if (ans >= -1000 && ans <= 1000)
        return true;
    return false;
}
int main() {
    int n;
    double sum = 0.0f;
    int cnt = 0;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        double tmp;
        if (check(s, tmp)) {
            sum += tmp;
            ++cnt;
        } else
            printf("ERROR: %s is not a legal number\n", s.c_str());
    }
    if (cnt > 1)
        printf("The average of %d numbers is %.2f\n", cnt, sum / cnt);
    else if (cnt == 1) // 单数、复数的英文表示不同，请注意。
        printf("The average of 1 number is %.2f\n", sum);
    else
        printf("The average of 0 numbers is Undefined\n");
    return 0;
}
