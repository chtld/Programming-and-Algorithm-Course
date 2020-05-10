#include<iostream>
#include<stack>
#include<queue>
using namespace std;

struct TreeNode{
    char ch;
    int tag;
    TreeNode* left;
    TreeNode* right;
    TreeNode(char c, int t): ch(c), tag(t){
        left = NULL;
        right = NULL;
    }
};

TreeNode* build(){
    int n;
    string str;
    cin >> n;
    if (n == 0) return NULL;
    stack<TreeNode*> sta;
    cin >> str;
    n--;
    TreeNode *root = new TreeNode(str[0], str[1] - '0');
    if (root->tag == 0) sta.push(root);
    while (n--) {
        TreeNode *parent = sta.top();
        cin >> str;
        TreeNode *cur = new TreeNode(str[0], str[1] - '0');
        if (NULL == parent->left) {
            parent->left = cur;
        } else if (NULL == parent->right) {
            parent->right = cur;
        } else {
            while (parent->right != NULL) {
                sta.pop();
                parent = sta.top();
            }
            parent->right = cur;
        }
        if (cur->tag == 0) sta.push(cur);
    }
    return root;
}

void print_mirror(TreeNode* root) {
    queue<TreeNode*> que;
    stack<TreeNode*> sta;
    que.push(root);
    while (!que.empty()) {
        TreeNode* cur = que.front();
        que.pop();
        if (cur->ch != '$') cout << cur->ch << " ";
        if (cur->left != NULL) {
            cur = cur->left;
            while (cur != NULL) {
                sta.push(cur);
                cur = cur->right;
            }
        }
        while (!sta.empty()) {
            que.push(sta.top());
            sta.pop();
        }
    }
    cout << endl;
    return;
}

void print(TreeNode *root){
    if (NULL == root) return;
    cout << root->ch << " ";
    print(root->left);
    print(root->right);
    return;
}

int main(){
    TreeNode* root = build();
    //print(root);
    //cout << endl;
    print_mirror(root);
    return 0;
}