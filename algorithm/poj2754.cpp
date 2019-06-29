#include<iostream>
#include<cstdio>

using namespace std;

int res[92][8], row[8], num = 0;

void queue(int x){
    if (x == 8) {
        for (int j = 0; j < 8; ++ j) {
            res[num][j] = row[j];
        }
        num++;
        return;
    }
    for (int j = 1; j <= 8; ++ j) {
        int k;
        for (k = 0; k < x; ++ k) {
            if (row[k] == j || abs(row[k] - j) == abs(k - x))
                break;
        }
        if (k == x) {
            row[k] = j;
            queue(x + 1);
        }
    }
    return;
}

int main(){
    int n, b;
    cin >> n;
    queue(0);
    for (int i = 0; i < n; ++ i) {
        cin >> b;
        for (int j = 0; j < 8; ++ j) {
            cout << res[b-1][j];
        }
        cout << endl;
    }
    return 0;
}