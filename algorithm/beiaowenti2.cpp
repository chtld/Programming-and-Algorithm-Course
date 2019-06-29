#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

#define MAX 60

struct Goods{
    int v;
    int w;
    double density;
    int index;
    int type;
    bool flag;
    bool cansl;
};

int N, m, sum = 0;
Goods goods[MAX];
double totv, totw;

bool operator < (const Goods &a, const Goods &b) {
    return a.density > b.density;
}

int main(){
    cin >> N >> m;
    int index = 1;
    for (int i = 0; i < m; ++ i) {
        cin >> goods[i].v >> goods[i].w >> goods[i].type;
        goods[i].flag = false;
        goods[i].density = 1.0*goods[i].w/goods[i].v;
        if (goods[i].type == 0) {
            goods[i].index = index;
            goods[i].cansl = true;
            index ++;
        } else {
            goods[i].index = 0;
            goods[i].cansl = false;
        }
    }
    sort(goods, goods+m);
//    for (int i = 0; i < m; ++ i) {
//        cout << goods[i].v << " " << goods[i].w << " " 
//        << goods[i].cansl << " " << goods[i].index 
//        << " " << goods[i].type << endl;
//    }
//    cout << endl;

    totv = totw = 0;
    bool mark = false;
    while (true) {
        for (int i = 0; i < m; ++ i) {
            if (goods[i].cansl) {
                if (totv + goods[i].v <= N) {
                    sum += goods[i].v * goods[i].w;
                    totv += goods[i].v;
                    totw += goods[i].w;
                    goods[i].cansl = false;
                    if (goods[i].type == 0) {
                        for (int j = 0; j < m; ++ j) {
                            if (goods[j].type == goods[i].index)
                                goods[j].cansl = true;
                        }
                    }
                    break;
                }
            }
            if (i == m - 1) mark = true;
        }
//    for (int i = 0; i < m; ++ i) {
//        cout << goods[i].v << " " << goods[i].w << " " 
//        << goods[i].cansl << " " << goods[i].index 
//        << " " << goods[i].type << endl;
//    }
//    cout << endl;
        if (mark) break;
    }
    printf("%d\n", sum);
    return 0;
}
