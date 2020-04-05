// runtime: 4ms
// space: 424K
// https://pintia.cn/problem-sets/994805342720868352/problems/994805509540921344
#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

const int MAX = 2001;

double seq[MAX];

struct Polynomial {
    int exponent; // 指数
    double coefficient; // 系数

    Polynomial(int e, double c): exponent(e), coefficient(c) {}
};

int main() {

    vector<Polynomial> A;
    vector<Polynomial> B;

    memset(seq, 0, sizeof(seq));

    // A
    int n;
    cin >> n;
    while (n--) {
        int e;
        double c;
        cin >> e >> c;
        A.push_back(Polynomial(e, c));
    }

    // B
    cin >> n;
    while (n--) {
        int e;
        double c;
        cin >> e >> c;
        B.push_back(Polynomial(e, c));
    }

    for (int i = 0; i < A.size(); ++i) {
        for (int j = 0; j < B.size(); ++j) {
            seq[A[i].exponent + B[j].exponent] += A[i].coefficient * B[j].coefficient;
        }
    }
    int count = 0;

    for (int i = 0; i < MAX; ++i) {
        if (seq[i] != 0) count++;
    }
    cout << count << " ";

    for (int i = MAX - 1; i >= 0; --i) {
        if (seq[i] == 0)
            continue;
        if (count-- == 1)
            printf("%d %.1lf", i, seq[i]);
        else
            printf("%d %.1lf ", i, seq[i]);

    }

    return 0;
}
