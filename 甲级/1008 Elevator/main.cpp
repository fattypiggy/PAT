// runtime: 5ms
// space: 384K
// https://pintia.cn/problem-sets/994805342720868352/problems/994805511923286016
#include <iostream>
using namespace std;

int main() {
    int n, current = 0, seconds = 0;
    cin >> n;
    while (n--) {
        int next;
        cin >> next;
        if (next > current) {
            seconds += (next - current) * 6;
        } else {
            seconds += (current - next) * 4;
        }

        seconds += 5;
        current = next;
    }
    cout << seconds << endl;
    return 0;
}
