#include<iostream>
#include<cstdio>
#include<algorithm>
#include<queue>

using namespace std;

struct Lake{
    int f, d, id;
};

#define MAXN 30

int n, h, ans;
int dist[MAXN];
int tmp[MAXN], best[MAXN];
Lake lake[MAXN];

priority_queue<Lake> fish;

bool operator < (const Lake &a, const Lake &b) {
    if (a.f == b.f)
        return a.id > b.id;
    else
        return a.f < b.f;
}



int main(){
    int now;
    Lake node;
    int times = 0, tt;
    while (scanf("%d", &n) != EOF) {
        if (n == 0) break;
        if (times != 0) printf("\n");
        times++;
        scanf("%d", &h);
        h *= 12;
        for (int i = 0; i < n; ++ i) {
            scanf("%d", &lake[i].f);
            lake[i].id = i;
            best[i] = 0;
        }
        for (int i = 0; i < n; ++ i) {
            scanf("%d", &lake[i].d);
        }
        dist[0] = 0;
        for (int i = 1; i < n; ++ i) {
            scanf("%d", &dist[i]);
            dist[i] += dist[i- 1];
        }
        ans = -1;
        for (int i = 0; i < n; ++ i) {
            now = 0;
            while (!fish.empty()) 
                fish.pop();
            for (int j = 0; j <= i; ++ j) {
                fish.push(lake[j]);
            }
            for (int j = 0; j < n; ++ j) {
                tmp[j] = 0;
            }
            tt = h - dist[i];
            while (tt > 0) {
                node = fish.top();
                fish.pop();
                tt--;
                now += node.f;
                tmp[node.id] ++;
                node.f -= node.d;
                if (node.f < 0) node.f = 0;
                fish.push(node);
            }
            if (now > ans) {
                ans = now;
                for (int j = 0; j < n; ++ j) {
                    best[j] = tmp[j];
                }
            }
        }
        for (int i = 0; i < n - 1; ++ i) {
            printf("%d, ", best[i] * 5);
        }
        printf("%d\n", best[n - 1] * 5);
        printf("Number of fish expected: %d\n", ans);
    }
    return 0;
}