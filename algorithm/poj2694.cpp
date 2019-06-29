#include<iostream>
#include<cstdio>
using namespace std;

double getValue(){
    string str;
    cin >> str;
    double a, b;
    switch(str[0]){
        case '+':
            a = getValue();
            b = getValue();
            return a + b;
            break;
        case '-':
            a = getValue();
            b = getValue();
            return a - b;
            break;
        case '*':
            a = getValue();
            b = getValue();
            return a * b;
            break;
        case '/':
            a = getValue();
            b = getValue();
            return a / b;
            break;
        default:
            return atof(str.c_str());
    }
}

int main(){
    double ans = getValue();
    printf("%.6f\n", ans);
    return 0;
}