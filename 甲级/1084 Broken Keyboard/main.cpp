// runtime: 5ms
// space: 384K
// 简单map题
#include <iostream>
#include <map>
#include <cctype>
using namespace std;

int main() {
    string before, after;
    cin >> before >> after;
    int i = 0, j = 0;
    map<char, bool> m;
    while (i < before.length()) {
        if (isalpha(before[i]))
            before[i] = toupper(before[i]);
        if (isalpha(after[j]))
            after[j] = toupper(after[j]);

        if (before[i] == after[j]) {
            i++;
            j++;
        } else {
            if (m[before[i]]) {
                i++;
            } else {
                m[before[i]] = true;
                cout<<before[i];
                i++;
            }
        }
    }
    return 0;
}
