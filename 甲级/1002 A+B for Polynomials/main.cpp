// runtime: 4ms
// https://pintia.cn/problem-sets/994805342720868352/problems/994805526272000000
#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

const int MAX = 1001;

double seq[MAX];
bool visit[MAX];

int main() {
    memset(visit, false, sizeof(visit));
    memset(seq, 0, sizeof(seq));

    int N, count = 0;
    // A
    cin >> N;
    while (N--) {
        int e;
        double c;
        cin>> e >> c;
        seq[e] += c;
    }
    // B
    cin >> N;
    while (N--) {
        int e;
        double c;
        cin>> e >> c;
        seq[e] += c;
    }

    for (int i = 0; i < MAX; ++i) {
        if (seq[i] != 0)
            count++;
    }

    cout << count;

    for (int i = MAX - 1; i >= 0; --i) {
        if (seq[i] != 0)
            printf(" %d %.1lf", i, seq[i]);
    }
    return 0;
}
