// runtime: 6ms
// space; 424K
// https://pintia.cn/problem-sets/994805342720868352/problems/994805454989803520
// 水题，简单的字符串操作题
#include <iostream>
using namespace std;

const int MAX = 1000;

struct node {
    string name;
    string pswd;
}info[MAX];

bool changed[MAX]; // 是否更改

int Solution(int n) {
    int count = 0;
    for (int i = 0; i < n; ++i) {
        bool flag = false;
        for (int j = 0; j < info[i].pswd.size(); ++j) {
            switch (info[i].pswd[j]) {
                case '1':
                    info[i].pswd[j] = '@';
                    flag = true;
                    break;
                case 'l':
                    info[i].pswd[j] = 'L';
                    flag = true;
                    break;
                case '0':
                    info[i].pswd[j] = '%';
                    flag = true;
                    break;
                case 'O':
                    info[i].pswd[j] = 'o';
                    flag = true;
                    break;
            }
        }
        if (flag) {
            count++;
            changed[i] = true;
        }
    }
    return count;
}

int main() {
    int n, m;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> info[i].name >> info[i].pswd;
    }

    m = Solution(n);

    if (m == 0) // 没有需要更改的password
        cout << "There " << (n > 1 ? "are" : "is") << " " << n << " " << (n > 1 ? "accounts" : "account") << " and no account is modified" << endl;
    else
        cout << m << endl;

    for (int i = 0; i < n; ++i) {
        if (changed[i])
            cout << info[i].name + " " + info[i].pswd << endl;
    }

    return 0;
}
