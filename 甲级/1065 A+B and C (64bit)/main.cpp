// runtime: 4ms
// space: 428K
// https://pintia.cn/problem-sets/994805342720868352/problems/994805406352654336
// 此题考察数据范围，注意溢出问题即可。
#include <iostream>
using namespace std;
int main() {
    int T;
    string s[2] = {"false", "true"};
    scanf("%d", &T);
    for (int i = 1; i <= T; ++i) {
        long long int a, b, c, sum;
        bool flag;
        scanf("%lld %lld %lld", &a, &b, &c);
        sum = a + b;
        if (a > 0 && b > 0 && sum < 0) { // 上溢出，不可能等于0
            flag = true;
        } else if (a < 0 && b < 0 && sum >= 0) { // 下溢出，sum == 0也有可能
            flag = false;
        } else if (sum > c) {
            flag = true;
        } else {
            flag = false;
        }
        printf("Case #%d: %s\n", i, s[flag].c_str());
    }
    return 0;
}
