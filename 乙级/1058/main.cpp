#include <iostream>
#include <bits/stdc++.h>
using namespace std;
struct Q {
    int score;
    int all;
    int len;
    string ans;
    Q (int s, int a, int l, string str) : score(s), all(a), len(l), ans(str) {}
};
int main() {
    int n, m;
    int s, a, l;
    cin >> n >> m;
    vector<Q> v;
    for(int i = 0; i < m; ++i) {
        cin >> s >> a >> l;
        string tmp;
        for (int j = 0; j < l; ++j) {
            char c;
            cin >> c;
            tmp += c;
        }
        v.emplace_back(s, a, l, tmp);
    }
    int max_wrong = 0;
    vector<int> wrong(m, 0);
    getchar();
    for (int i = 0; i < n; ++i) {
        string sheet;
        getline(cin, sheet);
        int q = 0;
        int sum = 0;
        for (size_t j = 0; j < sheet.size(); ++j) {
            if (sheet[j] == '(') {
                int len = sheet[j + 1] - '0';
                if (len != v[q].len) {
                    ++wrong[q];
                    max_wrong = max(max_wrong, wrong[q]);
                } else {
                    string ans;
                    for (int k = 1; k <= len; ++k) {
                        ans += sheet[j + 1 + k * 2];
                    }
                    if (ans == v[q].ans) {
                        sum += v[q].score;
                    } else {
                        ++wrong[q];
                        max_wrong = max(max_wrong, wrong[q]);
                    }
                }
                ++q;
            }
        }
        cout << sum << endl;
    }
    if (max_wrong == 0) {
        cout << "Too simple" << endl;
    } else {
        cout << max_wrong;
        for (int i = 0; i < m; ++i) {
            if (wrong[i] == max_wrong)
                cout << " " << i + 1;
        }
        cout << endl;
    }
    return 0;
}
