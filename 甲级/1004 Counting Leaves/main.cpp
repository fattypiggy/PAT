// runtime: 3ms
// https://pintia.cn/problem-sets/994805342720868352/problems/994805521431773184
#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
using namespace std;

const int MAX = 100;
vector<int> graph[MAX];
int answer[MAX];

struct Info {
    int id;
    int level;
    Info(int i, int l): id(i), level(l) {}
};

int main() {
    int n, m;
    while (cin >> n >> m) {
        if (n == 0)
            break;

        memset(graph, 0, sizeof(graph));
        memset(answer, 0, sizeof(answer));

        while (m--) {
            int id;
            int k;
            cin >> id >> k;
            while (k--) {
                int child_id;
                cin >> child_id;
                graph[id].push_back(child_id);
            }
        }

        queue<Info> q;
        q.push(Info(1, 0));
        int level; // 层数

        while (!q.empty()) {
            Info info = q.front();
            int id = info.id;
            level = info.level;
            q.pop();

            if (graph[id].size() == 0)
                answer[level]++;

            for (int i = 0; i < graph[id].size(); ++i) {
                q.push(Info(graph[id][i], level + 1));
            }
        }

        for (int i = 0; i <= level; ++i) {
            if (i == 0)
                cout << answer[i];
            else
                cout << " " << answer[i];
        }
        cout << endl;

    }
    return 0;
}
