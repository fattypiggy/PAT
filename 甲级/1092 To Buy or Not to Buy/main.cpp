// runtime: 4ms
// space: 384K
// https://pintia.cn/problem-sets/994805342720868352/problems/994805374509498368
// 水题，开一个数组存储每个字母有多少个珠子，然后分别减去需要的珠子，如果有负数，说明不够，如果没有负数，就用总数-需要的珠子，就是多买的珠子。
#include <iostream>
using namespace std;
const int MAX = 200;
int num[MAX];

int main() {
    string s1, s2;
    cin >> s1 >> s2;
    int len1 = s1.size(), len2 = s2.size(), sum = 0;
    for (int i = 0; i < len1; ++i) {
        num[s1[i]]++;
    }

    for (int i = 0; i < len2; ++i) {
        num[s2[i]]--;
    }

    for (int i = 0; i < MAX; ++i) {
        if (num[i] < 0)
            sum += num[i];
    }

    if (sum < 0) cout << "No " << -sum;
    else cout <<"Yes " << len1 - len2;
    return 0;
}
