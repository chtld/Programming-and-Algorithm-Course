#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

int str1[100001], str2[100001];
int n;

int main(){
    int maxLen1[100001];
    int maxLen2[100001];
    cin >> n;
    for (int i = 1; i <= n; ++ i) {
        cin >> str1[i];
    }
    for (int i = 1; i <= n; ++ i) {
        cin >> str2[i];
    }
    memset(maxLen1, 0, sizeof(maxLen1));
    memset(maxLen2, 0, sizeof(maxLen2));
        for (int i = 1; i <= n; ++ i) {
            for (int j = 1; j <= n; ++ j) {
                if (str1[i - 1] == str2[j - 1]) {
                    maxLen2[j] = maxLen1[j - 1] + 1;
                } else {
                    maxLen2[j] = max(maxLen1[j], maxLen2[j - 1]);
                }
            }
            for (int j = 0; j <= n; ++ j) {
                maxLen1[j] = maxLen2[j];
            }
        }
        cout << n - maxLen2[n] << endl;
    return 0;
}