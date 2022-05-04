#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    double e;
    int D;
    cin >> N >> e >> D;
    int maybe = 0, yes = 0;
    for (int i = 0; i < N; ++i) {
        int k;
        cin >> k;
        int cnt = 0;
        for (int j = 0; j < k; ++j) {
            double ee;
            cin >> ee;
            if (ee < e)
                ++cnt;
        }
        if (cnt > (k / 2)) {
            k > D ? ++yes : ++maybe; // 是k大于D，而不是cnt。卡了很久，仔细审题。
        }
    }
    double maybeRate = (double)maybe * 100 / N;
    double yesRate = (double)yes * 100 / N;
    printf("%.1f%% %.1f%%\n",maybeRate , yesRate);
    return 0;
}
