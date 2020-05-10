#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;

int a[1000005];

int main(){
    int val;
    int n, m;
    cin >> n;
    for (int i = 0; i < n; ++ i) {
        scanf("%d", &a[i]);
    }
    cin >> m;
    int i = 0;
    for (int j = 0; j < m; ++ j) {
        scanf("%d", &val);
        if (i >= n) {
            printf("%d ", val);
            continue;
        }
        if (val < a[i]) {
            printf("%d ", val);
        } else if (val > a[i]) {
            while (i < n && val > a[i]){
                printf("%d ", a[i]);
                ++i;
            }
            if (i < n && val == a[i]) {
                ++i;
            } else {
                printf("%d ", val);
            }
        } else {
            ++i;
        }
    }
    while (i < n) {
        printf("%d ", a[i]);
        ++i;
    }
    return 0;
}