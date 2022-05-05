#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
    int m, n, s;
    cin >> m >> n >> s;
    unordered_set<string> st;
    for (int i = 1; i <= m; ++i) {
        string str;
        cin >> str;
        if (i == s && st.find(str) != st.end()) {
            s += 1;
        }
        if (i == s && st.find(str) == st.end()) {
            st.insert(str);
            cout << str << endl;
            s += n;
        }
    }
    if (st.empty())
        cout << "Keep going..." << endl;
    return 0;
}
