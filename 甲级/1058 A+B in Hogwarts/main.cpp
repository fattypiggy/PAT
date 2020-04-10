// runtime: 3ms
// space: 256K
// https://pintia.cn/problem-sets/994805342720868352/problems/994805416519647232
// 水题，简单进制计算
#include <cstdio>

int main() {
    int g1, s1, k1, g2, s2, k2;
    scanf("%d.%d.%d %d.%d.%d", &g1, &s1, &k1, &g2, &s2, &k2);
    printf("%d.%d.%d", g1 + g2 + (s1 + s2 + (k1 + k2) / 29) / 17, (s1 + s2 + (k1 + k2) / 29) %17 ,(k1 + k2) % 29);
    return 0;
}
