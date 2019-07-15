#include<iostream>
#include<cstdio>
#include<queue>
#include<algorithm>

using namespace std;


struct Cow{
    int left;
    int right;
    int id;
    bool operator < (const Cow &b) const{
        return right > b.right;
    }
};
#define MAXN 50001
int N;
Cow cow[MAXN], node;
priority_queue<Cow> q;

bool cmp(const Cow &a, const Cow &b) {
    if (a.left == b.left) return a.right < b.right;
    else return a.left < b.left;
}

int main(){
    scanf("%d", &N);
    for (int i = 0; i < N; ++ i) {
        scanf("%d %d", &cow[i].left, &cow[i].right);
        cow[i].id = i;
    }
    sort(cow, cow + N, cmp);
    int ans = 0;
    int res[MAXN] = {0};
    for (int i = 0; i < N; ++ i) {
        if (!q.empty() && q.top().right < cow[i].left) {
                res[cow[i].id] = res[q.top().id];
                q.pop();
                q.push(cow[i]);
        } else {
            ans++;
            res[cow[i].id] = ans;
            q.push(cow[i]);
        }
    }
    printf("%d\n", ans);
    for (int i = 0; i < N; ++ i) {
        printf("%d\n", res[i]);
    }
    return 0;
}