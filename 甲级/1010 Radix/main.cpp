// runtime: 4ms
// space: 368K
// https://pintia.cn/problem-sets/994805342720868352/problems/994805507225665536
#include <iostream>
#include <algorithm>
#include <cctype>
using namespace std;

int CharToInt(char x) {
    if (x >= 'a' && x <= 'z') return x - 'a' + 10;
    else return x - '0';
}

// 转化为十进制
long long int ToDecimal(string s, long long int radix) {
    long long int num = 0;
    int len = s.size();
    for (int i = 0; i < len; ++i) {
        int digit = CharToInt(s[i]);
        if (digit == 0)
            continue;

        long long int tmp = digit;
        for (int j = 0; j < len - i - 1; ++j) {
            tmp *= radix;
        }
        num += tmp;
    }
    return num;
}

// 二分法找radix，提升效率。
long long int Compare(string s, long long int target) {
    char it = *max_element(s.begin(), s.end());
    long long low = (isdigit(it) ? it - '0' : it - 'a' + 10) + 1;
    long long int mid = low;
    long long int high = target + 1;
    while (low <= high) {
        long long int result = ToDecimal(s, mid);
        if (result == target) {
            return mid;
        } else if (result < 0 || result > target) { // result < 0 意味着溢出，柳婼NB！！！重要代码
            high = mid - 1;
        } else {
            low = mid + 1;
        }

        mid = (low + high) / 2;
    }
    return -1;
}

int main() {
    string N[2];
    int tag;
    long long int radix;
    cin >> N[0] >> N[1] >> tag >> radix;
    long long int target;

    target = ToDecimal(N[tag - 1], radix);

    long long int answer = Compare(N[2 - tag], target);

    if (answer != -1) {
        cout << answer << endl;
    } else {
        cout << "Impossible" << endl;
    }

    return 0;
}
