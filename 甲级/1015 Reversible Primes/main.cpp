// runtime: 4ms
// space: 368K
// https://pintia.cn/problem-sets/994805342720868352/problems/994805495863296000
#include <iostream>
#include <cmath>
using namespace std;

bool IsPrime(long long n) {
    if (n <= 1)
        return false;
    int max = sqrt(n);
    for (int i = 2; i <= max; ++i) {
        if (n % i == 0)
            return false;
    }

    return true;
}

int main() {
    int n, radix; // n是一个十进制数

    while (cin >> n) {

        if (n < 0)
            break;

        cin >> radix;

        if (!IsPrime(n)) {
            cout << "No" << endl;
            continue;
        }

        int arr[100]; // radix进制下的逆序列
        int len = 0;
        while (n > 0) {
            arr[len++] = n % radix;
            n /= radix;
        } // 结束时n == 0

        for (int i = len - 1; i >= 0; --i) {
            n += pow(radix, len - 1 - i) * arr[i];
        } // radix进制下的逆序列转换为10进制数

        if (IsPrime(n))
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
    return 0;
}
