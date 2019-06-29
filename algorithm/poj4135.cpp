#include<iostream>
#include<cstdio>
using namespace std;

#define MAX 100000

int N, M;
int a[MAX];

bool check(int mid) {
    int count = 0, temp = 0;
    for (int i = 0; i < N; ++ i) {
        if (temp + a[i] <= mid) {
            temp += a[i];
        } else {
            count ++;
            temp = a[i];
        }
    }
    if (count < M) return true;
    else return false;
}


int BinarySearch(int left, int right){
    int mid;
    while(left <= right) {
        mid = left + (right - left) / 2;
        if (check(mid)) {
            right = mid - 1;
        } else {
            left =  mid + 1;
        }
    }
    return right + 1;
}

int main(){
    int left = 0, right = 0;
    scanf("%d %d", &N, &M);
    for (int i = 0; i < N; ++ i) {
        scanf("%d", &a[i]);
        if (left < a[i]) left = a[i];
        right += a[i];
    }
    int ans = BinarySearch(left, right);
    printf("%d\n", ans);
    return 0;
}