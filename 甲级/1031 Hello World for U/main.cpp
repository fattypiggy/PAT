// runtime: 3ms
// space; 384K
// https://pintia.cn/problem-sets/994805342720868352/problems/994805462535356416
// 水题，二维数组问题
#include <iostream>
using namespace std;

const int MAX = 30;
char arr[MAX][MAX];

void Solution(string s, int r, int c) {
    int i = 0, j = 0, num = 0;

    while (num < s.size()) {
        arr[i][j] = s[num++];
        if (i < r - 1 && j == 0) i++;
        else if (i == r - 1 && j != c - 1) j++;
        else if (j == c - 1) i--;
    }
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            cout << (arr[i][j] == 0 ? ' ' : arr[i][j]);
            if (j == c - 1)
                cout << endl;
        }
    }
}

int main() {
    string str;
    cin >> str;

    int row, col;
    row = (str.size() + 2) / 3;
    col = str.size() + 2 - row * 2;

    Solution(str, row, col);
    return 0;
}
