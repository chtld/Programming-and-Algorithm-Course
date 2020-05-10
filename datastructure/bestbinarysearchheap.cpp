#include<iostream>
#include<cstdio>
#include<string>
#include<algorithm>
#include<cstring>
using namespace std;

int n;
struct node{
    char str[30];
    int val;
    int fa, l, r;
    bool operator<(node b) const {
        return strcmp(str,b.str)<0;
    }
};

node t[1000500];

void init(int n) {
    for (int i = 0; i <= n; ++ i) {
        t[i].l = t[i].r = t[i].fa = 0;
    }
    t[0].val = 0x3f3f3f3f;
}

void build() {
    for (int i = 1; i <= n; ++ i) {
        int j = i - 1;
        while (t[j].val < t[i].val) {
            j = t[j].fa;
        }
        t[i].l = t[j].r;
        t[j].r = i;
        t[i].fa = j;    
    }
    return;
}

void print(int u) {
    if (!u) return;
    printf("(");
    print(t[u].l);
    printf("%s/%d", t[u].str + 1, t[u].val);
    print(t[u].r);
    printf(")");
    return;
}

int main(){
    int i, j;
    while(scanf("%d", &n) && n) {
        init(n);
        for (i = 1; i <= n; ++ i) {
            scanf("%[^/]/%d", t[i].str, &t[i].val);
        }
        sort(t + 1,t + n + 1);
        build();
        print(t[0].r);
        printf("\n");
    }
    return 0;
}