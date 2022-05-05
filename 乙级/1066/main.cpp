#include <iostream>
using namespace std;
// 用cin输入会超时
int main() {
    int m, n, l, r, t;
    scanf("%d %d %d %d %d", &m, &n, &l, &r, &t);
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            int tmp;
            scanf("%d", &tmp);
            if (l <= tmp && tmp <= r)
                tmp = t;
            printf("%03d", tmp);
            if (j != n - 1)
                printf(" ");
        }
        printf("\n");
    }
    return 0;
}
