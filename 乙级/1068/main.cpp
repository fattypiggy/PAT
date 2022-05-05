#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main() {
    const int DIR[8][2] = {1, 0, -1, 0, 0, 1, 0, -1, 1, 1, 1, -1, -1, 1, -1, -1};
    int m, n, tol;
    cin >> m >> n >> tol;
    vector<vector<int>> mat(n, vector<int>(m));
    unordered_map<int, int> mp;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> mat[i][j];
            ++mp[mat[i][j]];
        }
    }
    int cnt = 0;
    int x, y;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (mp[mat[i][j]] > 1)
                continue;
            int max_circle = 0;
            bool flag = true;
            for (auto &row : DIR) {
                int dx = row[0], dy = row[1];
                int nx = i + dx, ny = j + dy;
                if (nx < 0 || nx >= n || ny < 0 || ny >= m)
                    continue;
                if (mat[i][j] - mat[nx][ny] >= -tol && mat[i][j] - mat[nx][ny] <= tol) {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                x = i, y = j;
                ++cnt;
            }
        }
    }
    if (cnt == 1)
        cout << "(" << y+1 << ", " << x+1 << "): " << mat[x][y] << endl;
    else if (cnt == 0)
        cout << "Not Exist" << endl;
    else
        cout << "Not Unique" << endl;

    return 0;
}
