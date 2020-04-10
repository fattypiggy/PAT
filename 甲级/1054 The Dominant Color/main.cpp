// runtime: 2ms - 86ms
// space: 368K
// https://pintia.cn/problem-sets/994805342720868352/problems/994805422639136768
// 此题略有坑，如果不用map，用数组统计个数的方式或者统计众数的算法，均会超时。
#include <cstdio>
#include <map>

using namespace std;

int main() {
    int m, n;
    scanf("%d %d", &m, &n);
    n = m * n;
    int half = n / 2;
    map<int, int> arr;
    for (int i = 0; i < n; ++i) {
        int temp;
        scanf("%d", &temp);
        arr[temp]++;
        if (arr[temp] > half) {
            printf("%d", temp);
            break;
        }
    }
    return 0;
}
