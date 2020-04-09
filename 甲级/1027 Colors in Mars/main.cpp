// runtime: 4ms
// space: 488K
// https://pintia.cn/problem-sets/994805342720868352/problems/994805470349344768
// 水题，考察进制转换
#include <iostream>
using namespace std;

string Solution(int color[], int size) {
    string answer = "#";
    for (int i = 0; i < size; ++i) {
        int digit = color[i];
        char left = (digit / 13) > 9 ? (digit / 13) - 10 + 'A' : (digit / 13) + '0';
        char right = (digit % 13) > 9 ? (digit % 13) - 10 + 'A' : (digit % 13) + '0';
        answer += left;
        answer += right;
    }
    return answer;
}

int main() {
    int color[3];
    cin >> color[0] >> color[1] >> color[2];
    cout << Solution(color, 3) << endl;
    return 0;
}
