// runtime: 5ms
// https://pintia.cn/problem-sets/994805342720868352/problems/994805504927186944
#include <iostream>
#include <cstdio>
using namespace std;

double rate[3][3];

char dictionary[3] = {'W', 'T', 'L'};

int main() {
    double a = 0, b = 0, c = 0;
    int index_a = 0, index_b = 0, index_c = 0;

    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            scanf("%lf", &rate[i][j]);
            if (i == 0 && rate[i][j] > a) {
                a = rate[i][j];
                index_a = j;
            } else if (i == 1 && rate[i][j] > b) {
                b = rate[i][j];
                index_b = j;
            } else if(i == 2 && rate[i][j] > c){
                c = rate[i][j];
                index_c = j;
            }
        }
    }

    double answer = (a * b * c * 0.65 - 1.0) * 2;

    printf("%c %c %c %.2lf\n", dictionary[index_a], dictionary[index_b], dictionary[index_c], answer);

    return 0;
}
