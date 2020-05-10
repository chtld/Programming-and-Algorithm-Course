#include<iostream>
#include<queue>
#include<vector>
#include<sstream>
#include<string>
#include<cstring>
using namespace std;

struct TreeNode{
    char ch;
    int degree;
    vector<TreeNode*> next;
    TreeNode(char c, int de){
        ch = c;
        degree = de;
    }
};

TreeNode* create(){
    char ch;
    int degree;
    queue<TreeNode*> que;
    cin >> ch >> degree;
    TreeNode* root = new TreeNode(ch, degree);
    que.push(root);
    while (!que.empty()) {
        TreeNode* cur = que.front();
        que.pop();
        for (int i = 0; i < cur->degree; ++ i) {
            cin >> ch >> degree;
            TreeNode *temp = new TreeNode(ch, degree);
            cur->next.push_back(temp);
            que.push(temp);
        }
    }
    return root;
}

void postorder (TreeNode* root) {
    if (NULL == root) return;
    for (int i = 0; i < root->degree; ++ i) {
        postorder(root->next[i]);
    }
    cout << root->ch << " ";
}


int main(){
    int n;
    cin >> n;
    while (n--) {
        TreeNode* root = create();
        postorder(root);
    }
    cout << endl;
    return 0;
}