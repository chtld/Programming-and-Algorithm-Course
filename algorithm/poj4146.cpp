#include<iostream>
#include<cstdio>

using namespace std;

int main(){
    int a1, a2, a3;
    int n;
    int rlt = 0;
    scanf("%d", &n);
    for (a1 = 0; a1 <= n; ++ a1) {
        for (a2 = 0; a2 <= n; ++ a2) {
            for (a3 = 0; a3 <= n; ++ a3) {
                if ((a1+a2)%2 == 0 && (a2+a3) % 3 == 0 && (a1+a2+a3) % 5 == 0) {
                    if ((a1+a2+a3) > rlt) {
                        rlt = a1+a2+a3;
                    }
                }
            }
        }
    }
    cout << rlt << endl;
    return 0;
}