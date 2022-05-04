#include <iostream>
#include <bits/stdc++.h>
using namespace std;
bool isPrime(int n) {
    for (int i = 2; i <= sqrt(n); ++i) {
        if (n % i == 0)
            return false;
    }
    return true;
}
int main() {
    int n;
    cin >> n;
    unordered_map<string, int> m;
    vector<int> vis(n + 1, 0);

    for (int i = 1; i <= n; ++i) {
        string id;
        cin >> id;
        m[id] = i;
    }
    int k;
    cin >> k;
    while (k--) {
        string id;
        cin >> id;
        int rank = m[id];

        if (rank != 0 && vis[rank]) {
            cout << id << ": Checked" << endl;
            continue;
        }

        if (rank == 0)
            cout << id << ": Are you kidding?" << endl;
        else if (rank == 1)
            cout << id << ": Mystery Award" << endl;
        else if (isPrime(rank))
            cout << id << ": Minion" << endl;
        else
            cout << id << ": Chocolate" << endl;
        vis[rank] = 1;
    }
    return 0;
}
