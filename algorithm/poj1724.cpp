#include<iostream>
#include<vector>
#include<cstring>

using namespace std;

int K, N, R;
struct road{
    int d, L, T;
};
vector<vector<road>> cityMap(110);
int minL[110][10100];
int visited[110];
int minLen = 1 << 30;
int totalLen;
int totalCost;

void dfs(int s) {
    if (s == N) {
        minLen = min(minLen, totalLen);
        return;
    }
    for (int i = 0; i < cityMap[s].size(); ++ i) {
        int d = cityMap[s][i].d;
        if (!visited[d]) {
            int cost = totalCost + cityMap[s][i].T;
            if (cost > K)
                continue;
            if (totalLen + cityMap[s][i].L >= minLen || totalLen + cityMap[s][i].L >= minL[d][cost])
                continue;
            totalLen += cityMap[s][i].L;
            totalCost += cityMap[s][i].T;
            minL[d][cost] = totalLen;
            visited[d] = 1;
            dfs(d);
            visited[d] = 0;
            totalLen -= cityMap[s][i].L;
            totalCost -= cityMap[s][i].T;
        }
    }
}


int main(){
    int s;
    cin >> K >> N >> R;
    for (int i = 0; i < R; ++ i) {
        road r;
        cin >> s;
        cin >> r.d >> r.L >> r.T;
        if (s != r.d)
            cityMap[s].push_back(r);
    }
    for (int i = 0; i < 110; ++ i) {
        for (int j = 0; j < 10100; ++ j) {
            minL[i][j] = 1 << 30;
        }
    }
    memset(visited, 0, sizeof (visited));
    totalLen = 0;
    totalCost = 0;
    visited[1] = 1;
    dfs(1);
    if (minLen < (1 << 30))\
        cout << minLen << endl;
    else 
        cout << -1 << endl;
    return 0;
}