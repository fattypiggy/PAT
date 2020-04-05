// runtime: 4ms
// space: 424K
// https://pintia.cn/problem-sets/994805342720868352/problems/994805458722734080
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;
struct OilStation {
    int dis;
    double price;

    OilStation(int d, double p): dis(d), price(p) {}
};

bool cmp(OilStation a, OilStation b) {
    return a.dis < b.dis;
}

vector<OilStation> v;

int main() {
    int C, D, avg, N;
    scanf("%d %d %d %d", &C, &D, &avg, &N);
    int MAX = C * avg;

    for (int i = 0; i < N; ++i) {
        double p;
        int d;
        scanf("%lf %d", &p, &d);

        v.push_back(OilStation(d, p));
    }

    sort(v.begin(), v.end(), cmp);

    int currentS = 0; // 当前station
    int nextS; // 下一个station
    double currentP = v[currentS].price; // 当前price
    double nextP; // 下一站price
    int dis = 0; // 当前距离
    double sum = 0.0;
    int leftDis = 0; // 上次加满后到nextP处还能走的距离。
    int type; // 加油类型

    // 有一个检测点起点就不是0，很坑。
    if (v[0].dis != 0) {
        printf("The maximum travel distance = 0.00\n");
        return 0;
    }

    while (dis <= D) {
        type = -1; // 已经到了最后一站
        nextP = 10000.0; // 假设成一个很大的值。
        for (int i = currentS + 1; i < N; ++i) {
            if (v[i].dis <= v[currentS].dis + MAX) {
                if (nextP > v[i].price) {
                    nextP = v[i].price;
                    nextS = i;
                }
            } else {
                break;
            }

            if (nextP <= currentP) {
                type = 1; // 遇到了更便宜的油，上一次加油加到此处
                break;
            } else {
                type = 2; // 上次加的油就是最便宜的，上一次加满
            }
        }

        if (type == 1) {
            // 遇到了更便宜的油，而且没到终点
            sum += (v[nextS].dis - dis - leftDis) * currentP;
        } else if (type == 2) {
            if (v[currentS].dis + MAX >= D) {
                // 能够到达
                sum += (D - v[currentS].dis) * v[currentS].price;
                printf("%.2lf\n", sum / 1.0 / avg);
                break;
            } else {
                // 还没到达终点
                sum += v[currentS].price * (MAX - leftDis);
                leftDis = dis + MAX - v[nextS].dis;
            }
        } else {
            // type == -1
            if (v[currentS].dis + MAX >= D) {
                // 能够到达
                sum += (D - v[currentS].dis) * v[currentS].price;
                printf("%.2lf\n", sum / 1.0 / avg);
                break;
            } else {
                // 不能到达终点
                printf("The maximum travel distance = %.2lf\n", double(v[currentS].dis + MAX));
                break;
            }
        }

        dis = v[nextS].dis; // 更新距离
        currentP = nextP;
        currentS = nextS;
    }
    return 0;
}
