// runtime: 5ms
// space: 384K
#include <cstdio>
#include <algorithm>
using namespace std;
int n, idx = 0;
int a[1001], level[1001];

void inOrder(int root)
{
    if (root > n)
    {
        return;
    }
    inOrder(root * 2);
    level[root] = a[idx++];
    inOrder(root * 2 + 1);
}
int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    sort(a, a + n);
    inOrder(1);
    for (int i = 1; i <= n; i++)
    {
        printf("%d", level[i]);
        if (i != n)
        {
            printf(" ");
        }
    }
    return 0;
}
