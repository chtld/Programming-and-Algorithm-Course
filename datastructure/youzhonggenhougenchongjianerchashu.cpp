#include<iostream>
#include<vector>
#include<string>
#include<sstream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<cstdlib>
using namespace std;

class TreeNode{
public:
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int value) {
        val = value;
        left = NULL;
        right = NULL;
    }
};

vector<int> inputline(){
    vector<int> res;
    int temp;
    string str;
    getline(cin, str);
    stringstream ss(str);
    while (ss >> temp) {
        res.push_back(temp);
    }
    return res;
}

TreeNode* BuildTree(vector<int>& inorder, int instart, int inend,
                        vector<int>& postorder, int poststart, int postend) {
    if (instart > inend || poststart > postend) return NULL;
    TreeNode* root = new TreeNode(postorder[postend]);
    int index = instart;
    while (postorder[postend] != inorder[index]) {
        ++index;
    }
    root->left = BuildTree(inorder, instart, index - 1,
                            postorder, poststart, poststart + index - 1 - instart);
    root->right = BuildTree(inorder, index + 1, inend,
                            postorder, poststart + index - instart, postend - 1);
    return root;
}

void pretraversal(TreeNode* root) {
    if (NULL == root) return;
    cout << root->val << " ";
    pretraversal(root->left);
    pretraversal(root->right);
    return;
}


int main() {
    vector<int> postorder, inorder, preorder;
    inorder = inputline();
    postorder = inputline();
    TreeNode *root = BuildTree(inorder, 0, inorder.size() - 1,
                                postorder, 0, postorder.size() - 1);
    pretraversal(root);
    cout << endl;
    return 0;
}