// runtime: 4mm
// space: 384K
// https://pintia.cn/problem-sets/994805342720868352/problems/994805523835109376
#include <iostream>
#include <climits>
#include <vector>
#include <queue>
using namespace std;

const int MAX = 500;

struct Edge {
    int to;
    int len;

    Edge(int t, int l ): to(t), len(l) {}
};

struct Point {
    int number;
    int distance;

    Point(int n, int d): number(n), distance(d) {}

    bool operator <(const Point& p) const {
        return distance > p.distance; // 距离小的优先级高
    }
};

int teamNum[MAX]; // 每个城市拥有的team
int dis[MAX]; // 源点到各城市最短距离
int maxTeam[MAX]; // 源点到各城市最多集结的team
int road[MAX]; // 最短路径的数量
vector<Edge> graph[MAX];

void Dijkstra(int s) {
    priority_queue<Point> q;
    dis[s] = 0;
    q.push(Point(s, dis[s]));

    while (!q.empty()) {
        int u = q.top().number;
        q.pop();

        for (unsigned int i = 0; i < graph[u].size(); ++i) { // 处理最短路径
            int to = graph[u][i].to;
            int len = graph[u][i].len;
            if (dis[to] > dis[u] + len) {
                dis[to] = dis[u] + len;
                road[to] = road[u]; // // 关键代码
                maxTeam[to] += maxTeam[u];
                q.push(Point(to, dis[to]));
            } else if (dis[to] == dis[u] + len) { // 处理最多team
                road[to] += road[u]; // 关键代码
                if (maxTeam[to] < (maxTeam[u] + teamNum[to]))
                    maxTeam[to] = maxTeam[u] + teamNum[to];
            }
        }
    }
}
int main() {
    int n, m, s, d;
    cin >> n >> m >> s >> d;

    for (int i = 0; i < n; ++i) {
        road[i] = 1; // 题目已经说明，至少有一条路
        dis[i] = INT_MAX; // 初始化为最大值
        cin >> teamNum[i];
        maxTeam[i] = teamNum[i];
    }
    for (int i = 0; i < m; ++i) {
        int from, to, len;
        cin >> from >> to >> len;
        graph[from].push_back(Edge(to, len));
        graph[to].push_back(Edge(from, len));
    }

    Dijkstra(s);

    cout << road[d] << " " << maxTeam[d] << endl;

    return 0;
}
