#include<iostream>
#include<string>
#include<cstdio>
using namespace std;

int main() {
    string str;
    int n;
    cin >> n;
    getchar();
    while (n --) {
        getline(cin, str);
        for (int i = 0; i < str.size(); ++ i) {
            if (str[i] <= 'Z' && str[i] >= 'A')
                str[i] = ((str[i] - 'A') + 1) % 26 + 'A';
            if (str[i] <= 'z' && str[i] >= 'a')
                str[i] = ((str[i] - 'a') + 1) % 26 + 'a';
        }
        cout << str << endl;
    }
    return 0;
}