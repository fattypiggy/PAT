#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main() {
    string pw;
    int n;
    cin >> pw >> n;
    string input;
    int cnt = 0;
    getchar();
    while (getline(cin, input)) {
        if (input == "#")
            break;
        if (input == pw) {
            cout << "Welcome in" << endl;
            break;
        } else {
            if (cnt < n) {
                cout << "Wrong password: " + input << endl;
                ++cnt;
                if (cnt == n) {
                    cout << "Account locked" << endl;
                    break;
                }
            }
        }
    }
    return 0;
}

