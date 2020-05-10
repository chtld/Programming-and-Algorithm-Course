#include<iostream>
#include<string>
#include<ctype.h>
#include<stack>
#include<map>
#include<algorithm>
#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<cmath>
using namespace std;

char out[50][300];

class TreeNode{
public:
    char c;
    TreeNode* left;
    TreeNode* right;
    TreeNode(char _c){
        c = _c;
        left = NULL;
        right = NULL;
    }
};

string infixtopostfix(string infix){
    string postfix = "";
    stack<char> sta;
    for (int j = 0; j < infix.size(); ++ j) {
        if (isalpha(infix[j])) {
            postfix += infix[j];
        } else if (infix[j] == '(') {
            sta.push(infix[j]);
        } else if (infix[j] == ')') {
            while (!sta.empty() && sta.top() != '(') {
                postfix += sta.top();
                sta.pop();
            }
            if (!sta.empty()) sta.pop();
        } else {
            while (!sta.empty() && sta.top() != '('
                    && (infix[j] == '+' || infix[j] == '-' || sta.top() == '*' || sta.top() == '/')) {
                postfix += sta.top();
                sta.pop();
            }
            sta.push(infix[j]);
        }
    }
    while (!sta.empty()) {
        postfix += sta.top();
        sta.pop();
    }
    return postfix;
}

int compute(string postfix, map<char, int> dict) {
    stack<int> sta;
    for (int i = 0; i < postfix.size(); ++ i) {
        if (isalpha(postfix[i])) {
            sta.push(dict[postfix[i]]);
        } else {
            int second = sta.top(); sta.pop();
            int first = sta.top(); sta.pop();
            int ans;
            switch (postfix[i]) {
                case '+':
                ans = first + second; 
                break;
                case '-':
                ans = first - second;
                break;
                case '*':
                ans = first * second;
                break;
                case '/':
                ans = first / second;
                break;
            }
            sta.push(ans);
        }
    }
    return sta.top();
}

TreeNode* build(string postfix) {
    stack<TreeNode*> sta;
    for (int i = 0; i < postfix.size(); ++ i) {
        TreeNode* cur = new TreeNode(postfix[i]);
        if (!isalpha(postfix[i])) {
            cur->right = sta.top(); sta.pop();
            cur->left = sta.top(); sta.pop();
        }
        sta.push(cur);
    }
    return sta.top();
}

int getheight(TreeNode* root) {
    if (root == NULL) return 0;
    int left = getheight(root->left);
    int right = getheight(root->right);
    return max(left, right) + 1;
}

void result(TreeNode *cur, int x, int y, int space) {
    out[x][y] = cur->c;
    if (NULL != cur->left) {
        out[x + 1][y - 1] = '/';
        result(cur->left, x + 2, y - space, space >> 1);
    }
    if (NULL != cur->right) {
        out[x + 1][y + 1] = '\\';
        result(cur->right, x + 2, y + space, space >> 1);
    }
}

void print(int height) {
    for (int i = 0; i < 2 * height - 1; ++ i) {
        int j = 299;
        while(out[i][j] == ' ') j--;
        out[i][j + 1] = 0;
        cout << out[i] << endl;
    }
}

int main(){
    string infix;
    cin >> infix;
    map<char, int> dict;
    int n;
    cin >> n;
    char c;
    int value;
    for (int i = 0; i < n; ++ i) {
        cin >> c >> value;
        dict[c] = value;
    }
    string postfix = infixtopostfix(infix);
    cout << postfix << endl;
    TreeNode* root = build(postfix);
    int height = getheight(root);
    memset(out, ' ', sizeof(out));
    int y =  pow(2, height - 1) - 1;
    result(root, 0, y, (y + 1) >> 1);
    print(height);
    int ans = compute(postfix, dict);
    cout << ans << endl;
    return 0;
}