#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;

bool visited[65536];

struct Node{
    int state;
    int step;
};

int change[16] =   //16种状态转换，对应4*4的翻子位置
{
	 51200,58368,29184,12544,
     35968,20032,10016,4880,
	 2248,1252,626,305,
	 140,78,39,19
};

int bfs(int state) {
    memset(visited, 0, sizeof(visited));
    queue<Node> q;
    Node cur, next;
    cur.state = state;
    cur.step = 0;
    q.push(cur);
    visited[state] = true;
    while(!q.empty()){
        cur = q.front();
        q.pop();
        if (cur.state == 0 || cur.state == 0xffff)
            return cur.step;
        for (int i = 0; i < 16; ++ i) {
            next.state = cur.state ^ change[i];
            next.step = cur.step + 1;
            if (visited[next.state])
                continue;
            visited[next.state] = true;
            q.push(next);
        }
    }
    return -1;
}


int main(){
    char ch[5][5];
    for (int i = 0; i < 4; ++ i) {
        cin >> ch[i];
    }
    int state = 0;
    for (int i = 0; i < 4; ++ i) {
        for (int j = 0; j < 4; ++ j) {
            state <<= 1;
            if (ch[i][j] == 'b')
                state += 1;
        }
    }
    int ans = bfs(state);
    if (ans == -1){
        cout << "Impossible" << endl;
    } else {
        cout << ans << endl;
    }
    return 0;
}