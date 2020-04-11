// runtime: 5ms
// space: 424K
// https://pintia.cn/problem-sets/994805342720868352/problems/994805395707510784
// 科学技术法的实现，不难，用Java大数代码更简单
#include <iostream>
#include <cstdlib>
using namespace std;

int main() {
    string s, result, first, second;
    cin >> s;
    char sign1 = s[0], sign2;
    first = s.substr(1, s.find_first_of('E') - 1);
    second = s.substr(s.find_first_of('E') + 1);
    sign2 = second[0];
    int num = abs((int)strtol(second.c_str(), nullptr, 10));


    //		左移
    if (sign2 == '-') {
        for (int i = 0; i < num; i++) {
            result.append("0");
        }

        first.erase(1, 1);
        result.append(first);
        result.insert(1, ".");

    } else if (sign2 == '+') { // 右移
        result.append(first);

        if (num >= first.length() - 2) {
            result.erase(1, 1);
            for (int i = 0; i < num - first.length() + 2; i++) {
                result.append("0");
            }
        } else {
            result.erase(1, 1); // 测试通过
            result.insert(num + 1, ".");
        }
    }

    if (sign1 == '-') {
        result.insert(0, "-");
    }

    cout << result << endl;

    return 0;
}
