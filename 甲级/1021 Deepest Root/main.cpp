// runtime: 5ms(max:1100ms)
// space: 680K
// https://pintia.cn/problem-sets/994805342720868352/problems/994805482919673856
// 此题考察DFS和并查集
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAXN = 10001;

vector<int> graph[MAXN];
int deep[MAXN];
bool visit[MAXN];

int DFS(int i) {
    if (visit[i]) return 0;
    visit[i] = true;

    int tmp, max_depth = 0;
    for (int j = 0; j < graph[i].size(); ++j) {
        if (!visit[graph[i][j]]) {
            tmp = DFS(graph[i][j]);
            max_depth = max(max_depth, tmp);
        }
    }
    return max_depth + 1;
}

int main() {
    int n, max_depth = 0, component = 1;
    scanf("%d", &n);
    for (int i = 0; i < n - 1; ++i) {
        int a, b;
        scanf("%d %d", &a, &b);
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    for (int i = 1; i <= n; ++i) {
        if (component == 1)
            memset(visit, 0, sizeof(visit));
        deep[i] = DFS(i);
        max_depth = max(deep[i], max_depth);

        for (int j = i; j <= n; ++j) {
            if (!visit[j]) {
                component++;
                i = j - 1; // 关键代码，缺少的话会少通过一个测试点
                break;
            }
        }
    }

    if (component == 1) {
        for (int i = 1; i <= n; ++i) {
            if (deep[i] == max_depth)
                cout << i << endl;
        }
    } else {
        cout << "Error: "<< component <<" components" << endl;
    }
    return 0;
}
