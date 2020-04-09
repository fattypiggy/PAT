// runtime: 58ms
// space: 384K
// https://pintia.cn/problem-sets/994805342720868352/problems/994805444361437184
// 我远程此题为最水的题😂
#include <iostream>
using namespace std;
const int MAX = 10000;

int frequency[MAX]; // 用来记录频次
int main() {
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
        frequency[arr[i]]++;
    }

    for (int i = 0; i < n; ++i) {
        if (frequency[arr[i]] == 1) {
            cout << arr[i] << endl;
            return 0;
        }
    }
    cout << "None" <<endl;
    return 0;
}
