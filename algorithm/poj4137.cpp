#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

char n[20];
int m, k, t;

int main(){
    int i, count;
    cin >> t;
    while (t--) {
        count = 0;
        cin >> n >> k;
        int length = strlen(n);
        while (k--) {
            for (int i = 0; i < length; ++ i) {
                if (n[i] > n[i + 1]) {
                    for (int j = i; j < length; ++ j) {
                        n[j] = n[j + 1];
                    }
                    length--;
                    break;
                }
            }
        }
        cout << n << endl;
    }
    return 0;
}