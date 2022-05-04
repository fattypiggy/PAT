#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
int main() {
    int N;
    cin >> N;
    vector<int> v(N);
    for (int i = 0; i < N; ++i) {
        cin >> v[i];
    }
    sort(v.begin(), v.end(), greater<int>());
    int m = 1, n = 1;
    for (int i = 2; i <= sqrt(N); ++i) {
        if (N % i == 0)
            n = i;
    }
    m = N / n;
    vector<vector<int>> matrix(m, vector<int>(n, 0));
    int index = 0;
    int up = 0, bottom = m - 1, left = 0, right = n - 1;
    while (index < N) {
        for (int j = left; j <= right; ++j)
            matrix[up][j] = v[index++];
        ++up;
        if (index >= N)
            break;
        for (int i = up; i <= bottom; ++i)
            matrix[i][right] = v[index++];
        --right;
        if (index >= N)
            break;
        for (int j = right; j >= left; --j)
            matrix[bottom][j] = v[index++];
        --bottom;
        if (index >= N)
            break;
        for (int i = bottom; i >= up; --i)
            matrix[i][left] = v[index++];
        ++left;
        if (index >= N)
            break;
    }
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << matrix[i][j] << (j == n - 1 ? "" : " ");
        }
        cout << endl;
    }
    return 0;
}

