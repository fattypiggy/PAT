// runtime: 5ms
// space: 384K
// https://pintia.cn/problem-sets/994805342720868352/problems/994805390896644096
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    string s, ans;
    getchar();

    for (int i = 0; i < n; ++i) {
        getline(cin, s);
        reverse(s.begin(), s.end());

        if (i == 0) {
            ans = s;
            continue;
        } else {
            int len = s.length();
            int ans_len = ans.length();
            int min_len = min(ans_len, len);
            if (len < ans_len) swap(s, ans);
            for (int j = 0; j < min_len; ++j) {
                if (ans[j] != s[j]) {
                    ans = ans.substr(0, j);
                    break;
                }
            }
        }
    }
    reverse(ans.begin(), ans.end());
    if (ans.length() == 0)
        ans = "nai";

    cout << ans << endl;
    return 0;
}
