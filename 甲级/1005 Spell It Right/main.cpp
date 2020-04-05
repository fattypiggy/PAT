// runtime: 3ms
// space: 384K
// https://pintia.cn/problem-sets/994805342720868352/problems/994805519074574336
#include <iostream>
using namespace std;

string dictionary[10] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

int main() {
    string s;
    cin >> s;
    int sum = 0;
    for (unsigned int i = 0; i < s.length(); ++i) {
        sum += (s[i] - '0');
    }

    string answer = to_string(sum);

    for (unsigned int i = 0; i < answer.size(); ++i) {
        if (i == 0)
            cout << dictionary[answer[i] - '0'];
        else
            cout << " " << dictionary[answer[i] - '0'];
    }
    cout << endl;

    return 0;
}
