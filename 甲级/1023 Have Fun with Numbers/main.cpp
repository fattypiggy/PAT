// runtime: 4mm
// space: 384K
// https://pintia.cn/problem-sets/994805342720868352/problems/994805478658260992
// 此题考察的是模拟大数乘以二
#include <iostream>
using namespace std;

int cInt1[10], cInt2[10]; // 0-9的个数

void Solution(string s) {
    int size = s.size();
    string dblNum; // 存放乘以2的结果
    int tmp = 0; // 临时进位

    for (int i = size - 1; i >= 0; --i) {
        cInt1[s[i] - '0']++;

        int digit = (s[i] - '0') * 2;
        dblNum.insert(dblNum.begin(), (digit % 10 + tmp) + '0');
        cInt2[digit % 10 + tmp]++;
        tmp = digit / 10;

        // 如果第一个数大于等于5，会产生进位
        if (i == 0 && tmp == 1) {
            dblNum.insert(dblNum.begin(), '1');
            cInt2[1]++;
        }
    }

    bool flag = true;
    for (int i = 0; i < 10; ++i) {
        if (cInt1[i] != cInt2[i]) {
            flag = false;
            break;
        }
    }

    cout << (flag ? "Yes" : "No") << endl << dblNum;
}
int main() {
    string s;
    cin >> s;
    Solution(s);
}
