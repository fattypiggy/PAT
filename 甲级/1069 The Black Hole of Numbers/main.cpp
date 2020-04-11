// runtime: 4ms
// space: 384K
// https://pintia.cn/problem-sets/994805342720868352/problems/994805400954585088
// 此题不难，注意输出细节 %04d 即可AC
#include <cmath>
#include <algorithm>
using namespace std;

void Convert(int n, int* a, int* b) {
    int arr[4] = {0, 0, 0, 0}, i = 3;
    while (n) {
        arr[i--] = n % 10;
        n /= 10;
    }
    sort(arr, arr + 4);
    *a = 0;
    *b = 0;
    for (int j = 0; j < 4; ++j) {
        *b += (arr[j] * pow(10, 3- j));
        *a += (arr[j] * pow(10, j));
    }
}

int main() {
    int n, left, right;
    scanf("%d", &n);

    Convert(n, &left, &right);

    if (left == right) {
        printf("%04d - %04d = %04d\n", left, right, 0);
        return 0;
    }

    while (1) {
        printf("%04d - %04d = %04d\n", left, right, left-right);
        if (left - right == 6174)
            break;
        Convert(left-right, &left, &right);
    }
    return 0;
}
