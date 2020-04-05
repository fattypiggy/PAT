// runtime: 4ms
// https://pintia.cn/problem-sets/994805342720868352/problems/994805528788582400
#include <iostream>
#include <string>

using namespace std;

int main() {
    int a, b;
    cin >> a >> b;
    string str = to_string(a + b);

    int len = str.length() - 3;

    int pos = 0;
    if (str[0] == '-') {
        pos = 1;
    }

    while (len > pos) {
        str.insert(len, ",");
        len -= 3;
    }
    cout << str << endl;
    return 0;
}
