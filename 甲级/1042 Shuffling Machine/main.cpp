// runtime: 4ms
// space: 424K
// https://pintia.cn/problem-sets/994805342720868352/problems/994805442671132672
// 水题不解释
#include <iostream>
using namespace std;
const int MAX = 55;
string card[MAX];

void Init() {
    for (int i = 1; i <= 13; ++i) {
        string s = to_string(i);
        card[i] = "S" + s;
        card[i + 13] = "H" + s;
        card[i + 26] = "C" + s;
        card[i + 39] = "D" + s;
    }
    card[53] = "J1";
    card[54] = "J2";
}

void Solution(int n, int seq[]) {
    string temp[MAX];
    for (int i = 0; i < n; ++i) {
        for (int j = 1; j < MAX; ++j) {
            temp[seq[j]] = card[j];
        }

        for (int k = 1; k < MAX; ++k) {
            card[k] = temp[k];
        }
    }

    for (int i = 1; i < MAX; ++i) {
        cout << card[i] << (i == MAX - 1 ? "" : " ");
    }
}

int main() {
    int times, seq[MAX];
    Init();
    cin >> times;
    for (int i = 1; i < MAX; ++i) {
        cin>> seq[i];
    }

    Solution(times, seq);
    return 0;
}
