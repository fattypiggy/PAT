// runtime: 4ms
// space: 386K
// https://pintia.cn/problem-sets/994805342720868352/problems/994805487143337984
// description: 简单题，考查的是进制转换。
#include <iostream>
using namespace std;

const int MAX = 10000;

int num[MAX];

void LetsGO(int decimal, int base) {
    int i = 0;
    bool flag = true;
    while (decimal) {
        num[i++] = decimal % base;
        decimal /= base;
    }

    for (int j = 0; j < i / 2; ++j) {
        if (num[j] != num[i - 1 - j]) {
            flag = false;
            break;
        }
    }

    printf("%s\n", flag ? "Yes" : "No");

    if (i >= 1) {
        for (int j = i - 1; j >= 0; --j) {
            printf("%d", num[j]);
            if (j > 0) printf(" ");
        }
    } else {
        printf("%d", 0); // 这个if-else修复了一个输入为0 2的bug，即i = 0所以，除了yes，不会输出数字0
    }

}

int main() {
    long long int decimal, base;
    scanf("%lld %lld", &decimal, &base);
    LetsGO(decimal, base);
    return 0;
}
