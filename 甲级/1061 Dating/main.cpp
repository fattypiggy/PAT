// runtime: 5ms
// space: 384K
// https://pintia.cn/problem-sets/994805342720868352/problems/994805411985604608
// 水题，但是此处有坑：'A' <= s1[i] && s1[i] <= 'G' 因为第一个字母是代表周几，所以不能超过'G'
#include <iostream>
#include <cctype>
using namespace std;

string day[7] = {
        "MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"
};

int main() {
    string s1, s2, s3, s4;
    bool found_first = false;
    cin >> s1 >> s2 >> s3 >> s4;
    for (int i = 0; i < s1.length(); ++i) {
        if (s1[i] == s2[i] && 'A' <= s1[i] && s1[i] <= 'G' && !found_first) { // 此处有坑
            printf("%s ", day[s1[i] - 'A'].c_str());
            found_first = true;
            continue;
        }

        if (s1[i] == s2[i] && found_first) {
            if ('0' <= s1[i] && s1[i] <= '9') {
                printf("%02d:", s1[i] - '0');
                break;
            } else if ('A' <= s1[i] && s1[i] <= 'N') {
                printf("%02d:", s1[i] - 'A' + 10);
                break;
            }
        }
    }

    for (int i = 0; i < s3.length(); ++i) {
        if (s3[i] == s4[i] && isalpha(s3[i])) {
            printf("%02d", i);
            break;
        }
    }
    return 0;
}
