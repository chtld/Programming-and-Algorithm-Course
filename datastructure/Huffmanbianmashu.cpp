#include<iostream>
#include<vector>
#include<queue>
using namespace std;

struct TreeNode{
    int weight;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int wei) {
        weight = wei;
        left = NULL;
        right = NULL;
    }
};
struct cmp {
    bool operator() (const TreeNode* a, const TreeNode* b) {
        return a->weight > b->weight;
    }
};

TreeNode* build(priority_queue<TreeNode*, vector<TreeNode*>,cmp>& pq) {
    TreeNode *parent, *left, *right;
    int len = pq.size() - 1;
    for (int i = 0; i < len; ++ i) {
        left = pq.top(); pq.pop();
        right = pq.top(); pq.pop();
        parent = new TreeNode(left->weight + right->weight);
        parent->left = left;
        parent->right = right;
        pq.push(parent);
    }
    return parent;
}

int weightoutpath(TreeNode* root) {
    int res = 0, level = 0;
    queue<TreeNode*> que;
    que.push(root);
    while (!que.empty()) {
        int len = que.size();
        for (int i = 0; i < len; ++ i) {
            TreeNode* cur = que.front();
            que.pop();
            if (NULL == cur->left && NULL == cur->right) {
                res += cur->weight * level;
            }
            if (NULL != cur->left) que.push(cur->left);
            if (NULL != cur->right) que.push(cur->right);
            //cout << cur->weight << " ";
        }
        level++;
    }
    return res;
}

void preorder(TreeNode* root) {
    if (NULL == root) return;
    cout << root->weight << endl;
    preorder(root->left);
    preorder(root->right);
}

int main() {
    int n = 0;
    priority_queue<TreeNode*, vector<TreeNode*>, cmp> pq;
    cin >> n;
    for (int i = 0; i < n; ++ i) {
        int weight;
        cin >> weight;
        TreeNode* temp = new TreeNode(weight);
        pq.push(temp);
    }
    TreeNode* root = build(pq);
    // preorder(root);
    int ans = weightoutpath(root);
    cout << ans << endl;
    return 0;
}