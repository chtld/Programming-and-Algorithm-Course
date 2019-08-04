#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int n;
int s;
int a, b;
int A[10020], B[10010];
int F[10010];

int main(){
    cin >> n;
    while (n --) {
        cin >> s;
        cin >> a;
        for (int i = 1; i <= a; ++ i) {
            cin >> A[i];
        }
        cin >> b;
        for (int i = 1; i <= b; ++i) {
            cin >> B[i];
        }
        memset(F, 0, sizeof(F));
        for (int i = 1; i <= a; ++ i) {
            int temp1 = 0, temp2 = 0;
            for (int j = 1; j <= b; ++ j) {
                temp2 = F[j];
                F[j] = F[j] + F[j - 1] - temp1;
                if (A[i] + B[j] == s)
                    F[j]++;
                temp1 = temp2;
            }
        }
        cout << F[b] << endl;
    }
    return 0;
}