#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

int n, w;

struct Box{
    int v;
    int w;
    double density;
};

Box box[100];

bool operator <(const Box &a, const Box &b){
    return a.density < b.density;
}

int main(){
    double totv = 0.;
    int totw = 0, i = 0;
    scanf("%d %d", &n, &w);
    for (i = 0; i < n; ++ i) {
        scanf("%d %d", &box[i].v, &box[i].w);
        box[i].density = 1.0 * box[i].v / box[i].w;
    }
    sort(box, box + n);
    for (i = n - 1; i >= 0; -- i) {
        if (totw + box[i].w <= w) {
            totw += box[i].w;
            totv += box[i].v;
        } else {
            break;
        }
    }
    if (totw < w) {
        totv += (w - totw) * box[i].density;
    }
    printf("%.1lf\n", totv);
    return 0;
}
