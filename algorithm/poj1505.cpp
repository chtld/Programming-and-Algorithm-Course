#include<iostream>
#include<cstdio>

using namespace std;

int m, k;
int p[501];
int N;
int l, r, mid;

bool check(int ans) {
    int cur = 0, count = 0;
    for (int i = m - 1; i >= 0; -- i) {
        if ((cur + p[i]) > ans) {
            count++;
            cur = p[i];
        } else {
            cur += p[i];
        }
    }
    if (cur > 0) count++;
    return count <= k;
}

void print(int book, int ans, int scriber, long long now){
    bool sepa = false;
    if (book < 0) return;
    if (book == scriber-1 || now + p[book] > ans) {
        print(book - 1, ans, scriber - 1, p[book]);
        sepa = true;
    } else {
        print(book - 1, ans, scriber, now + p[book]);
    }
    if (book > 0) printf(" %d", p[book]);
    else printf("%d", p[book]);
    if (sepa) printf(" /");
}

int main(){
    cin >> N;
    while (N--) {
        l = 0;
        r = 0;
        mid = 0;
        cin >> m >> k;
        for (int i = 0; i < m; ++ i) {
            cin >> p[i];
            if (l < p[i])
                l = p[i];
            r += p[i];
        }
        while (l <= r) {
            mid = l + (r - l) / 2;
            if (check(mid))
                r = mid - 1;
            else
                l = mid + 1;
        }
        print(m - 1, l, k - 1, 0);
        printf("\n");
    }
    return 0;
}