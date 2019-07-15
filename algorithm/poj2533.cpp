#include<iostream>
#include<cstdio>

using namespace std;

int N;
int a[1005], maxLen[1005];

int main(){
    int ans = 0;
    cin >> N;
    for (int i = 0; i < N; ++ i) {
        cin >> a[i];
    }
    maxLen[0] = 1;
    for (int i = 1; i < N; ++ i) {
        int temp = 0;
        for (int j = 0; j < i; ++ j) {
            if (a[i] > a[j]) {
                if (temp < maxLen[j]) 
                    temp = maxLen[j];
            }
        }
        maxLen[i] = temp + 1;
    }
    for (int i = 0; i < N; ++ i) {
        if (ans < maxLen[i]) 
            ans = maxLen[i];
    }
    cout << ans << endl;
    return 0;
}