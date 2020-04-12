// runtime: 4ms
// space: 384K
// https://pintia.cn/problem-sets/994805342720868352/problems/994805386161274880
// 挺有意思的一道题，手动求最简分数运算，这里需要用到最大最大公约数和最小公倍数
// 中间的约分处理这一步很重要，否则可能出现最大公约数溢出的问题，所以每次计算完后都要约分。
#include <iostream>

long long GCD(long a, long b) {
    if (b == 0)
        return a;
    else {
        return GCD(b, a % b);
    }
}

long long LCM(long a, long b) {
    return a * b / GCD(a, b);
}

int main() {
    long long n, integer, remainder, numerator, denominator, ans_num, ans_de;
    scanf("%lld", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%lld/%lld", &numerator, &denominator);

        if (i == 0) {
            ans_num = numerator;
            ans_de = denominator;
            continue;
        } else {
            long long lcm = LCM(denominator, ans_de);
            ans_num = lcm / ans_de * ans_num + lcm / denominator * numerator;
            ans_de = lcm;

            // 约分处理
            long long gcd = GCD(ans_num, ans_de);
            ans_num /= gcd;
            ans_de /= gcd;
        }
    }

    integer = ans_num / ans_de; // 整数
    remainder = ans_num % ans_de; // 余数

    if (integer != 0) { // 整数不为0
        if (remainder != 0) { // 余数不为0
            printf("%ld %ld/%ld", integer, remainder, ans_de);
        } else {
            printf("%ld", integer);
        }
    } else { // 整数为0
        if (remainder != 0) { // 余数不为0
            printf("%ld/%ld", remainder, ans_de);
        } else { // 余数为0
            printf("0");
        }
    }
    return 0;
}
