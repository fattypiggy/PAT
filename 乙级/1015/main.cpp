#include <iostream>
#include <bits/stdc++.h>
using namespace std;
struct Info {
    int id, d, c, sum;
    Info(int id, int d, int c, int sum = 0) : id(id), d(d), c(c), sum(sum) {}
    bool operator < (const Info &a) const {
        if (sum == a.sum) {
            if (d == a.d)
                return id < a.id;
            else
                return d > a.d;
        } else
            return sum > a.sum;
    };
};
int main() {
    int N, l, h;
    cin >> N >> l >> h;
    int count = 0;
    vector<vector<Info>> v(4, vector<Info>());
    for (int i = 0; i < N; ++i) {
        int id, d, c;
        cin >> id >> d >> c;
        if (d < l || c < l) {
            ++count;
            continue;
        }
        if (d >= h && c >= h) {
            v[0].emplace_back(id, d, c, d + c);
        } else if (d >= h && c < h) {
            v[1].emplace_back(id, d, c, d + c);
        } else if (d < h && d >= c) {
            v[2].emplace_back(id, d, c, d + c);
        } else {
            v[3].emplace_back(id, d, c, d + c);
        }
    }
    cout << N - count << endl;
    for (auto& r : v) {
        sort(r.begin(), r.end());
        for (const auto &i : r) {
            cout << i.id << " " << i.d << " " <<  i.c << endl;
        }
    }
    return 0;
}
