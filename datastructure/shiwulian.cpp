#include<iostream>

using namespace std;

#define N 50010

struct node{
    int pre;
    int relation;
};

node p[N];

int find(int x) {
    int temp;
    if (x == p[x].pre)
        return x;
    temp = p[x].pre;
    p[x].pre = find(temp);
    p[x].relation = (p[x].relation + p[temp].relation) % 3;
    return p[x].pre;
}

int main(){
    int n, k;
    int ope, x, y;
    int rootx, rooty;
    int count = 0;
    cin >> n >> k;
    for (int i = 1; i <= n; ++ i) {
        p[i].pre = i;
        p[i].relation = 0;
    }
    for (int i = 0; i < k; ++ i) {
        cin >> ope >> x >> y;
        if (x > n || y > n) {
            count++;
            continue;
        }
        if (ope == 2 && x == y) {
            count++;
            continue;
        }
        rootx = find(x);
        rooty = find(y);
        if (rootx != rooty) {
            p[rooty].pre = rootx;
            p[rooty].relation = (3 - p[y].relation + p[x].relation + (ope - 1)) % 3;
        } else {
            if (ope == 1 && p[x].relation != p[y].relation) {
                count++;
                continue;
            }
            if (ope == 2 && (3 - p[x].relation + p[y].relation) % 3 != 1) {
                count++;
                continue;
            }
        }
    }
    cout << count << endl;
    return 0;
}