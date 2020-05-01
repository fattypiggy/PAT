// runtime: 5ms
// space: 424K
// https://pintia.cn/problem-sets/994805342720868352/problems/994805367156883456
// 进制转换水题。
#include <iostream>
#include <cstdlib>
#include <cctype>
#include <map>
using namespace std;

string dic[2][13] = {
        {"tret", "jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec"},
        {"tret", "tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou"}
};
int main() {
    int n;
    cin >> n;

    map<string, string> high;
    map<string, string> low;
    for (int i = 0; i < 13; ++i) {
        low.insert(make_pair(dic[0][i], to_string(i)));
        low.insert(make_pair(to_string(i), dic[0][i]));
        high.insert(make_pair(dic[1][i], to_string(i)));
        high.insert(make_pair(to_string(i), dic[1][i]));
    }
    getchar();
    while (n-- > 0) {
        string str;
        getline(cin, str);
        if (isdigit(str[0])) {
            int num = atoi(str.c_str());
            if (num <= 12) {
                cout << low[to_string(num)] << endl;
            } else if (num % 13 == 0) {
                cout << high[to_string(num / 13)] << endl;
            } else {
                cout << high[to_string(num / 13)] + " " + low[to_string(num % 13)] << endl;
            }
        } else {
            if (str.length() == 7) {
                string left = str.substr(0, str.find(" "));
                string right = str.substr(str.find(" ") + 1);
                cout << atoi(high[left].c_str()) * 13 + atoi(low[right].c_str()) << endl;
            } else {
                if (low.find(str) != low.end()) {
                    cout << low[str].c_str() << endl;
                } else {
                    cout << atoi(high[str].c_str()) * 13 << endl;
                }
            }

        }
    }
    return 0;
}
