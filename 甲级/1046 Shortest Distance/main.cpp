// runtime: 13ms
// space: 692K
// https://pintia.cn/problem-sets/994805342720868352/problems/994805435700199424
// 此题虽是20分，但是绝对不是水题，很多人会卡在只得17分，要么超时，要么超过空间。
#include <cstdio>
#include <algorithm>
using namespace std;
const int MAX = 100001;
int dis[MAX];

int main() {
    int n, m, sum = 0;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &dis[i]);
        sum += dis[i];
        dis[i] = sum; // 前i个和
    } // dis[0] = 0;

    scanf("%d", &m);
    for (int j = 0; j < m; ++j) {
        int a, b;
        scanf("%d %d", &a, &b);
        if (a > b) {
            int tmp = a;
            a = b;
            b = tmp;
        }

        // dis[b-1] - dis[a-1]的解释： 比如求 2-5的距离，应该是1-5的距离dis[4]减去1-2的距离dis[1]。
        // 然后求sum减去此数的另外一个顺序的距离，取两者的最小值。
        printf("%d\n", min(dis[b - 1] - dis[a - 1], sum - dis[b - 1] + dis[a - 1]));
    }
    return 0;
}
