// runtime: 4ms
// space: 512K
// https://pintia.cn/problem-sets/994805342720868352/problems/994805500414115840
#include <cstdio>
#include <vector>

using namespace std;
const int MAX = 1000;

vector<int> graph[MAX];

int father[MAX];
int height[MAX];

void Init() { // 初始化
    for (int i = 0; i < MAX; ++i) {
        father[i] = i;
        height[i] = 1;
    }
}

int Find(int x) { // 查找
    if (x != father[x]) {
        father[x] = Find(father[x]); // 优化高度
    }
    return father[x];
}

void Union(int a, int b) { // 合并
    a = Find(a);
    b = Find(b);

    if (height[a] < height[b]) {
        father[a] = b;
    } else if (height[a] > height[b]) {
        father[b] = a;
    } else {
        father[b] = a;
        height[a]++;
    }
}

int BuildUnion(int n, int except) { // 主要逻辑
    Init();
    int count = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < graph[i].size(); ++j) { // 除了except的点，其余全部进行并查集
            if (i == except || graph[i][j] == except)
                continue;

            Union(i, graph[i][j]);
        }
    }

    for (int i = 1; i <= n; ++i) {
        if (i == except)
            continue;

        if (father[i] == i)
            count++; // count指一共有多少个集合
    }

    return count - 1; // 输出count - 1即所需要最少的路
}

int main() {
    int N, M, K;
    scanf("%d %d %d", &N, &M, &K);

    Init();

    while (M--) {
        int c1, c2;
        scanf("%d %d", &c1, &c2);
        graph[c1].push_back(c2);
        graph[c2].push_back(c1);
    }
    
    while (K--) {
        int c;
        scanf("%d", &c);
        printf("%d\n", BuildUnion(N, c));
    }

    return 0;
}
