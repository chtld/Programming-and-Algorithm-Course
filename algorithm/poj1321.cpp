#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

char a[10][10];
int n, k;
int num, cases;
int visited[10];

void dfs(int r){
    if (num == k) {
        cases++;
        return;
    }
    if (r >= n) 
        return;
    for (int j = 0; j < n; ++ j) {
        if (!visited[j] && a[r][j] == '#') {
            num++;
            visited[j] = 1;
            dfs(r + 1);
            visited[j] = 0;
            num--;
        }
    }
    dfs(r + 1);
}


int main(){
    while (true){
        cin  >> n >> k;
        if (n == -1)
            break;
        for (int i = 0; i < n; ++ i) {
            for (int j = 0; j < n; ++ j) {
                cin >> a[i][j];
            }
        }
        memset(visited, 0, sizeof(visited));
        num = 0;
        cases = 0;
        dfs(0);
        cout << cases << endl;
    }
    return 0;
}
