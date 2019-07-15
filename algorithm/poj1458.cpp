#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

char str1[202], str2[202];

int main(){
    int maxLen[202][202];
    while (cin >> str1 >> str2) {
        int len1 = strlen(str1);
        int len2 = strlen(str2);
        memset(maxLen, 0, sizeof(maxLen));
        for (int i = 1; i <= len1; ++ i) {
            for (int j = 1; j <= len2; ++ j) {
                if (str1[i - 1] == str2[j - 1]) {
                    maxLen[i][j] = maxLen[i - 1][j - 1] + 1;
                } else {
                    maxLen[i][j] = max(maxLen[i - 1][j], maxLen[i][j - 1]);
                }
            }
        }
        cout << maxLen[len1][len2] << endl;
    }
    return 0;
}