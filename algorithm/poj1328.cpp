#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;

struct Node{
    int x, y;
    double left, right;
};

bool operator<(const Node &a, const Node &b) {
    return a.left < b.left;
}


int main(){
    int n, d;
    Node node[1005];
    int cases = 1;
    bool flag = true;
    int count;
    double temp;
    while (scanf("%d %d", &n, &d) != EOF) {
        flag = true;
        if(n == 0 && d == 0) break;
        for (int i = 0; i < n; ++ i) {
            cin >> node[i].x >> node[i].y;
            if (node[i].y > d) {
                flag = false;
            }
            node[i].left = 1.0*node[i].x-sqrt(d*d - node[i].y*node[i].y);
            node[i].right = 1.0*node[i].x+sqrt(d*d - node[i].y*node[i].y);
        }
        if (flag) {
            sort(node, node + n);
            temp = node[0].right;
            count = 1;
            for (int i = 1; i < n; ++ i) {
                if (node[i].left <= temp) {
                    if (temp >= node[i].right)
                        temp = node[i].right;
                } else {
                    count++;
                    temp = node[i].right;
                }
            }
            printf("Case %d: %d\n", cases, count);
        } else {
            printf("Case %d: -1\n", cases);
        }
        cases++;
    }
    return 0;
}