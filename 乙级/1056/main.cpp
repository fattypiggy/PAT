#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; ++i)
        cin >> nums[i];
    int sum = 0;
    for (int i = 0; i < nums.size(); ++i) {
        for (int j = 0; j < nums.size(); ++j) {
            if (i == j)
                continue;
            sum += nums[i] * 10 + nums[j];
        }
    }
    cout << sum << endl;
    return 0;
}
