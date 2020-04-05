// runtime: 3ms
// space: 384K
// https://pintia.cn/problem-sets/994805342720868352/problems/994805516654460928
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct Info{
    string id;
    string time;

    bool operator <(const Info& i) const {
        return time > i.time; // 小顶堆
    }

    Info(string i, string t): id(i), time(t) {}
};

struct cmp
{
    bool operator()(Info a, Info b) {
        return a.time < b.time; // 大顶堆
    }
};

int main() {
    int n;
    priority_queue<Info> in;
    priority_queue<Info, vector<Info>, cmp> out;
    cin >> n;
    while (n--) {
        string id, sign_in, sign_out;
        cin >> id >> sign_in >> sign_out;

        in.push(Info(id, sign_in));
        out.push(Info(id, sign_out));
    }

    cout << in.top().id << " " << out.top().id << endl;

    return 0;
}
