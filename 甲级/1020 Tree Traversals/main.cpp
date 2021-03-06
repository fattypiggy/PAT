// runtime: 4ms
// space: 384K
// https://pintia.cn/problem-sets/994805342720868352/problems/994805485033603072
#include <cstdio>
#include <queue>
using namespace std;

const int MAXN = 32;
int post[MAXN];
int in[MAXN];

struct TreeNode {
    int data;
    TreeNode* leftChild;
    TreeNode* rightChild;
    TreeNode(int n): data(n), leftChild(NULL), rightChild(NULL) {}
};
// 二叉树构建
TreeNode* Build(int root, int start, int end) {
    if (start > end) // 退出标志
        return NULL;
    int i = start;
    while (i < end && in[i] != post[root]) i++;
    TreeNode* tree = new TreeNode(post[root]);
    tree->leftChild = Build(root - end + i - 1, start, i - 1); // 计算边界
    tree->rightChild = Build(root - 1, i + 1, end); // 计算边界
    return tree;
}
// 层序遍历
void LevelTraversal(TreeNode* root, int n) {
    int i = 0;
    queue<TreeNode*> q;
    if (root != NULL) {
        q.push(root);
    }

    while (!q.empty()) {
        TreeNode* current = q.front();
        q.pop();
        if(i++ < n - 1)
            printf("%d ", current->data);
        else
            printf("%d", current->data);

        if (current->leftChild != NULL) {
            q.push(current->leftChild);
        }
        if (current->rightChild != NULL) {
            q.push(current->rightChild);
        }
    }
}

int main() {
    int N;
    scanf("%d", &N);
    for (int i = 0; i < N; ++i) {
        scanf("%d", &post[i]);
    }
    for (int i = 0; i < N; ++i) {
        scanf("%d", &in[i]);
    }
    TreeNode* root = Build(N - 1, 0, N - 1);
    LevelTraversal(root, N);
    return 0;
}
