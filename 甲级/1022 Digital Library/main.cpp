// runtime: 5ms(max:579ms)
// space: 500K(max:6528K)
// https://pintia.cn/problem-sets/994805342720868352/problems/994805480801550336
// 题目不难，虽然是30分的题目。本题考察map自带排序属性。
#include <iostream>
#include <cstdio>
#include <map>
using namespace std;

int main() {
    int n;
    map<string, string> m[6];
    cin >> n;
    getchar();
    while (n--) {
        string id, title, author, keywords, publisher, year;
        getline(cin ,id);
        getline(cin ,title);
        getline(cin ,author);
        getline(cin ,keywords);
        getline(cin ,publisher);
        getline(cin ,year);

        m[1][id] = title;
        m[2][id] = author;
        m[3][id] = keywords;
        m[4][id] = publisher;
        m[5][id] = year;
    }
    cin >> n;
    getchar();
    while (n--) {
        string query;
        bool found = false;
        getline(cin, query);
        cout << query << endl;
        int index = query[0] - '0';

        for (map<string, string>::iterator  it = m[index].begin(); it != m[index].end(); it++) {
            if ((index == 3 && it->second.find(query.substr(3)) != string::npos) || it->second == query.substr(3)) {
                cout << it->first << endl;
                found = true;
            }
        }
        if (!found) cout << "Not Found" << endl;
    }
    return 0;
}
