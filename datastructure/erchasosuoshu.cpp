#include<iostream>
#include<sstream>
#include<string>
#include<cstring>
using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int value){
        val = value;
        left = NULL;
        right = NULL;
    }
};

void preorder (TreeNode* root) {
    if (NULL == root) return;
    cout << root->val << " ";
    preorder(root->left);
    preorder(root->right);
}

void insert (TreeNode*& root, int value) {
    if (root == NULL) {
        root = new TreeNode(value);
        return;
    }
    TreeNode* cur = root;
    while (NULL != cur) {
        if (value > cur->val) {
            if (NULL == cur->right) {
                cur->right = new TreeNode(value);
                return;
            }
            cur = cur->right;
        } else if (value < cur->val) {
            if (NULL == cur->left) {
                cur->left = new TreeNode(value);
                return;
            }
            cur = cur->left;
        } else {
            return;
        }
    }
}

int main(){
    string str;
    int value;
    TreeNode* root = NULL;
    getline(cin, str);
    //cout << str << " ";
    stringstream ss(str);
    //ss >> value;
    //root = new TreeNode(value);
    while (ss >> value) {
        //cout << value << endl;
        insert(root, value);
    }
    preorder(root);
    return 0;
}