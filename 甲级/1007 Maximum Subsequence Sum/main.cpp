// runtime: 8ms
// space: 424K
// https://pintia.cn/problem-sets/994805342720868352/problems/994805514284679168
#include <iostream>
#include <algorithm>
#include <climits>
const int MAX = 10001;

int arr[MAX]; // 输入数组
int dp[MAX]; // dp[i]指的是：以arr[i]为结尾的最大连续子序列的和。

using namespace std;

int MaxSubsequence(int n) {
    int index = 0; // 返回值是dp里的最大值的下标
    int maximum = INT_MIN;
    for (int i = 0; i < n; ++i) {
        if (i == 0) {
            dp[i] = arr[i];
        }
        else {
            dp[i] = max(arr[i], dp[i - 1] + arr[i]);
        }

        if (dp[i] >maximum) {
            maximum = dp[i];
            index = i;
        }
    }

    if (maximum < 0) {
        index = -1; // 所有数都是负数
    }

    return index;
}

int main() {
    int n;

    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    int index = MaxSubsequence(n);
    int start = 0; // 从index开始从后往前查找，第一个dp[i]为非负数的下标。

    if (index == -1) {
        printf("0 %d %d\n", arr[0], arr[n - 1]);
    } else {
        for (int i = index; i >= 0; --i) {
            if (dp[i] < 0) {
                start = i + 1;
                break;
            }
        }
        printf("%d %d %d\n", dp[index], arr[start], arr[index]);
    }

    return 0;
}
