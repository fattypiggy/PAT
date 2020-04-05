// runtime: 7ms
// space: 512K
// https://pintia.cn/problem-sets/994805342720868352/problems/994805502658068480
#include <iostream>
#include <algorithm>

using namespace std;

struct Node {
    int id, best; // 最好的排名所对应的下标
    int score[4]; // A C M E 四科成绩
    int rank[4]; // A C M E 四科排名
}stu[2001];

int exist[1000000]; // 存储最后一次sort后的下标
int flag = -1; // 单科排名序号 A C M E
char dictionary[4] = {'A', 'C', 'M', 'E'};

bool cmp (Node n1, Node n2) {
    return n1.score[flag] > n2.score[flag];
}

int main() {
    int N, M;
    scanf("%d %d", &N, &M);

    for (int i = 0; i < N; ++i) {
        int id, c, m, e;
        scanf("%d %d %d %d", &id, &c, &m, &e);
        stu[i].id = id;
        stu[i].score[0] = int((c + m + e) / 3.0 + 0.5); // 四舍五入，此处注意！
        stu[i].score[1] = c;
        stu[i].score[2] = m;
        stu[i].score[3] = e;
    }

    for (int i = 0; i < 4; ++i) {
        flag = i;
        sort(stu, stu + N, cmp); // 按照单科顺序依次排序

        /**
         * 排序有个规则，比如： 1 1 2 2 3 就是错误的，
         * 而应该是 1 1 3 3 5。
         */
        stu[0].rank[i] = 1;
        for (int j = 1; j < N; ++j) {
            if (stu[j].score[i] == stu[j - 1].score[i])
                stu[j].rank[i] = stu[j-1].rank[i];
            else
                stu[j].rank[i] = j + 1;
        }
    }

    for (int i = 0; i < N; ++i) {
        exist[stu[i].id] = i + 1; // 在最后一次排序过后再记录index，+1是为了规避0
        int best = 0;
        for (int j = 1; j < 4; ++j) {
            if (stu[i].rank[j] < stu[i].rank[best]) {
                best = j;
                stu[i].best = j;
            }
        }
    }

    while (M--) {
        int id;
        scanf("%d", &id);
        int index = exist[id];

        if (index) {
            int best = stu[index - 1].best;
            printf("%d %c\n", stu[index - 1].rank[best], dictionary[best]);
        } else {
            printf("N/A\n");
        }
    }

    return 0;
}
