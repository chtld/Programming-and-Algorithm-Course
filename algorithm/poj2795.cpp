#include<cstdio>
#include<algorithm>

using namespace std;

struct Metal{
    int weight;
    int value;
    double density;
};

Metal metal[100];
int n, s, k, w, totw = 0;
double ans = 0.0;

bool operator < (const Metal &a, const Metal &b) {
    return a.density < b.density;
}

int main(){
    int i;
    scanf("%d", &k);
    while (k--) {
        ans = 0.0;
        totw = 0;
        scanf("%d", &w);
        scanf("%d", &s);
        for (i = 0; i < s; ++ i) {
            scanf("%d %d", &metal[i].weight, &metal[i].value);
            metal[i].density = 1.0 * metal[i].value / metal[i].weight;
        }
        sort(metal, metal + s);
        for (i = s - 1; i >= 0; -- i) {
            if ((totw + metal[i].weight) > w) {
                ans += (w - totw) * metal[i].density; 
                break;
            } else {
                totw += metal[i].weight;
                ans += metal[i].value;
            }
        }
        
        printf("%.2lf\n", ans);
    }
    return 0;
}