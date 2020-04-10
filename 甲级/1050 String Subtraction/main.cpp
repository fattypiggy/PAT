// runtime: 4ms
// space: 412K
// https://pintia.cn/problem-sets/994805342720868352/problems/994805429018673152
// 水题
#include <iostream>
using namespace std;

const int MAX = 300;

bool dic[MAX];

int main() {
    string s1, s2;
    getline(cin, s1);
    getline(cin, s2);

    int len1 = s1.length(), len2 = s2.length();

    for (int i = 0; i < len2; ++i) {
        dic[s2[i]] = true;
    }

    for (int i = 0; i < len1; ++i) {
        if (dic[s1[i]])
            continue;
        cout << s1[i];
    }
    return 0;
}
