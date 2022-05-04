#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> orig(n), seq(n);
    for (int i = 0; i < n; ++i) {
        cin >> orig[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> seq[i];
    }
    int index;
    for (index = 1; index < n && seq[index] >= seq[index - 1]; ++index) {} // 这里需要 >=

    bool isInsert = true;
    for (int j = index; j < n; ++j) {
        if (orig[j] != seq[j]) {
            isInsert = false;
            break;
        }
    }
    if (isInsert) {
        cout << "Insertion Sort" << endl;
        sort(orig.begin(), orig.begin() + index + 1);
    } else {
        cout << "Merge Sort" << endl;
        int k = 1, flag = 1;
        while (flag) {
            flag = 0;
            for (int i = 0; i < n; ++i) {
                if (orig[i] != seq[i]) {
                    flag = 1;
                    break;
                }
            }
            k *= 2;
            for (int i = 0; i < n / k; ++i) {
                sort(orig.begin() + i * k, orig.begin() + (i + 1) * k);
            }
            sort(orig.begin() + n / k * k, orig.end());
        }
    }
    for (int i = 0; i < n; ++i) {
        cout << orig[i] << (i < n - 1 ? " " : "");
    }
    return 0;
}
