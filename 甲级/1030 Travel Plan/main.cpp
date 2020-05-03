// runtime: 4ms
// space: 384K
// link: https://pintia.cn/problem-sets/994805342720868352/problems/994805464397627392
// 最短路径的变形题目。
#include <cstring>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <climits>
#include <queue>
#include <stack>
using namespace std;

const int MAX = 500;
const int INF = INT_MAX;

struct Edge {
    int to;
    int distance;
    int cost;
    Edge(int t, int d, int c): to(t), distance(d), cost(c) {}
};

struct Point {
    int number;
    int distance;
    Point(int n, int d): number(n), distance(d) {}
    bool operator< (const Point& p) const {
        return distance > p.distance;
    }
};

int path[MAX]; // 路径
int dis[MAX]; // 原点到各点的最小距离
int cost[MAX]; // 原点到各点的最小开销
vector<Edge> graph[MAX];

void Dijkstra(int s) {
    priority_queue<Point> q;
    dis[s] = 0;
    cost[s] = 0;
    q.push(Point(s, dis[s]));
    while (!q.empty()) {
        int u = q.top().number;
        q.pop();
        for (int i = 0; i < graph[u].size(); ++i) {
            int to = graph[u][i].to;
            int len = graph[u][i].distance;
            int c = graph[u][i].cost;

            if (dis[to] > dis[u] + len) {
                dis[to] = dis[u] + len;
                cost[to] = cost[u] + c; // 和常规最短路径相比，多记录一下cost
                q.push(Point(to, dis[to]));
                path[to] = u;
            } else if (dis[to] == dis[u] + len && cost[to] > cost[u] + c) { // 和常规最短路径相比，多记录一下cost
                cost[to] = cost[u] + c;
                path[to] = u;
            }
        }
    }
    return ;
}

int main() {
    int N, M, S, D;
    scanf("%d %d %d %d", &N, &M, &S, &D);
    memset(graph, 0, sizeof(graph));
    fill(dis, dis + N, INF);
    fill(cost, cost + N, INF);
    for (int i = 0; i < M; ++i) {
        int from, to, dis, cost;
        scanf("%d %d %d %d", &from, &to, &dis, &cost);
        graph[from].push_back(Edge(to, dis, cost));
        graph[to].push_back(Edge(from, dis, cost));
    }

    Dijkstra(S);

    stack<int> s;
    int d = D;

    while (d != S) {
        s.push(path[d]);
        d = path[d];
    }

    while (!s.empty()) {
        printf("%d ", s.top());
        s.pop();
    }

    printf("%d %d %d", D, dis[D], cost[D]);
    return 0;
}
