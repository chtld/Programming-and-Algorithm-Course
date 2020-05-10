#include<iostream>
#include<string>
#include<stack>
#include<cstring>
#include<cstdio>
using namespace std;

string intopost(string infixexp) {
    string postfixexp = "";
    stack<char> sta;
    for (int i = 0; i < infixexp.size(); ++ i) {
        if ((infixexp[i] >= '0' && infixexp[i] <= '9')
            || (infixexp[i] >= 'A' && infixexp[i] <= 'Z')
            || (infixexp[i] >= 'a' && infixexp[i] <= 'z')) {
            postfixexp += infixexp[i];        
        } else if (infixexp[i] == '(') {
            sta.push(infixexp[i]);
        } else if (infixexp[i] == ')') {
            if (sta.empty()) {
                cerr << "error occured in inpost!" << endl;
                break;
            } else {
                while (sta.top() != '(' ) {
                    char temp = sta.top();
                    sta.pop();
                    postfixexp += temp;
                }
                if (sta.empty()) cerr << "error occured in inpost2!" << endl;
                sta.pop();
            }
        } else if (infixexp[i] == '+' || infixexp[i] == '-') {
            while (!sta.empty() && sta.top() != '(') {
                postfixexp += sta.top();
                sta.pop();
            }
            sta.push(infixexp[i]);
        } else if (infixexp[i] == '*') {
            while (!sta.empty() && sta.top() != '(' && sta.top() == '*') {
                postfixexp += sta.top();
                sta.pop();
            }
            sta.push(infixexp[i]);
        } else if (infixexp[i] == ' ' || infixexp[i] == '   ') {
            continue;
        }   
    }
    while (!sta.empty()) {
        postfixexp += sta.top();
        sta.pop();
    }
    return postfixexp;
}

int calculate (string postfixexp) {
    int ans = 0;
    stack<int> sta;
    for (int i = 0; i < postfixexp.size(); ++ i) {
        if (postfixexp[i] >= '0' && postfixexp[i] <= '9') {
            sta.push(postfixexp[i] - '0');
        } else if (postfixexp[i] >= 'A' && postfixexp[i] <= 'Z') {
            sta.push((int)postfixexp[i]);
        } else if (postfixexp[i] >= 'a' && postfixexp[i] <= 'z') {
            sta.push((int)postfixexp[i]);
        } else {
            int num2 = sta.top(); sta.pop();
            int num1 = sta.top(); sta.pop();
            switch (postfixexp[i]) {
                case '+':
                    sta.push(num1 + num2);
                    break;
                case '-':
                    sta.push(num1 - num2);
                    break;
                case '*':
                    sta.push(num1 * num2);
                    break;
            }
        }
    }
    //cout << sta.size() << endl;
    return sta.top();
}



int main(){
    int cases;
    cin >> cases;
    getchar();
    while (cases --) {
        string infixexp1, infixexp2;
        getline(cin, infixexp1);
        // cerr << infixexp1 << endl;
        getline(cin, infixexp2);
        // cerr << infixexp2 << endl;
        string postfixexp1, postfixexp2;
        postfixexp1 = intopost(infixexp1);
        postfixexp2 = intopost(infixexp2);
        // cout << postfixexp1 << endl;
        // cout << postfixexp2 << endl;
        int num1 = calculate(postfixexp1);
        int num2 = calculate(postfixexp2);
        if (num1 == num2) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}