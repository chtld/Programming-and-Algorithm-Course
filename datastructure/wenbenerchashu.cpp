#include<iostream>
#include<string>
#include<vector>
#include<stack>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<cstdlib>
using namespace std;

class TreeNode{
public:
    char val;
    int deepth;
    int dir;
    TreeNode* left;
    TreeNode* right;
    TreeNode(char value) {
        val = value;
        deepth = 0;
        dir = 0;
        left = NULL;
        right = NULL;
    }
};

void pretraversal(TreeNode* root) {
    if (NULL == root) return;
    cout << root->val;
    pretraversal(root->left);
    pretraversal(root->right);
}

void intraversal(TreeNode* root) {
    if (NULL == root) return; 
    intraversal(root->left);
    cout << root->val;
    intraversal(root->right);
}

void posttraversal(TreeNode* root) {
    if (NULL == root) return; 
    posttraversal(root->left);
    posttraversal(root->right);
    cout << root->val;
}

TreeNode* build(vector<string>& data) {
    stack<TreeNode*> sta;
    TreeNode* root = new TreeNode(data[0][0]);
    sta.push(root);
    for (int i = 1; i < data.size(); ++ i) {
        int deepth = data[i].size() - 1;
        TreeNode* p1 = new TreeNode(data[i][deepth]);
        p1->deepth = deepth;
        TreeNode* p2 = sta.top();
        if (p1->val == '*') {
            p2->dir++;
            continue;
        }
        while (p1->deepth - p2->deepth != 1) {
            sta.pop();
            p2 = sta.top();
        }
        if (p2->dir == 0) {
            p2->left = p1;
            p2->dir++;
        } else if (p2->dir == 1) {
            p2->right = p1;
            p2->dir++;
        } else if (p2->dir == 2) {
            sta.pop();
        }
        sta.push(p1);
    }
    return root;
}

int main() {
    int n = 0;
    cin >> n;
    string str;
    vector<string> data;
    while (n--) {
        data.clear();
        while (cin >> str) {
            if (str[0] == '0') break;
            data.push_back(str);
        }
        TreeNode* root = build(data);
        pretraversal(root);
        cout << endl;
        posttraversal(root);
        cout << endl;
        intraversal(root);
        cout << endl << endl;
    }
    return 0;
}