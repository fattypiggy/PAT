#include <iostream>
#include <bits/stdc++.h>
using namespace std;
struct Line {
    string n;
    int h;
    Line(string n, int h) : n(n), h(h) {}
};
int main() {
    int n, k;
    cin >> n >> k;
    vector<Line> info;
    for (int i = 0; i < n; ++i) {
        string n;
        int h;
        cin >> n >> h;
        info.emplace_back(n, h);
    }
    sort(info.begin(), info.end(), [](Line& l1, Line& l2) -> bool {
        if (l1.h != l2.h)
            return l1.h > l2.h;
        else
            return l1.n < l2.n;
    });
    int index = 0;
    vector<deque<string>> lines(k, deque<string>());
    for (int i = 0; i < k; ++i) {
        const int m = (i == 0 ? n - (k - 1) * n / k : n / k);
        bool flag = true;
        int j = 0;
        while (j++ < m) {
            if (flag) {
                lines[i].push_back(info[index].n);
            } else {
                lines[i].push_front(info[index].n);
            }
            ++index;
            flag = !flag;
        }
    }
    for (int i = 0; i < lines.size(); ++i) {
        for (int j = 0; j < lines[i].size(); ++j) {
            cout << lines[i][j] << (j == lines[i].size() - 1 ? "" : " ");
        }
        cout << endl;
    }
    return 0;
}
