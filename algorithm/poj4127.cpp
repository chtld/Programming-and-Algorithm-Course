#include<iostream>
#include<cstdio>
#include<queue>
#include<cstring>
#include<stack>
using namespace std;

int maze[6][6];
bool visited[6][6];
struct Step{
    int r, c;
    Step(int rr, int cc) : r(rr), c(cc) {}
    Step():r(0), c(0) {}
};
queue<Step> q;
stack<Step> routes;
Step route[6][6];

int main(){
    for (int i = 0; i < 5; ++ i) {
        for (int j = 0; j < 5; ++ j) {
            cin >> maze[i][j];
        }
    }
    memset(visited, 0, sizeof(visited));
    visited[0][0] = true;
    q.push(Step(0, 0));
    route[0][0].r = -1;
    route[0][0].c = -1;
    while(!q.empty()) {
        Step s = q.front();
        if (s.r == 4 && s.c == 4) {
            break;
        } else {
            if (s.r - 1 >= 0 && maze[s.r - 1][s.c] == 0 && !visited[s.r - 1][s.c]) {
                q.push(Step(s.r - 1, s.c));
                route[s.r - 1][s.c].c = s.c;
                route[s.r - 1][s.c].r = s.r;
                visited[s.r - 1][s.c] = true;
            }
            if (s.r + 1 <= 4 && maze[s.r + 1][s.c] == 0 && !visited[s.r + 1][s.c]) {
                q.push(Step(s.r + 1, s.c));
                route[s.r + 1][s.c].c = s.c;
                route[s.r + 1][s.c].r = s.r;
                visited[s.r + 1][s.c] = true;
            }
            if (s.c - 1 >= 0 && maze[s.r][s.c - 1] == 0 && !visited[s.r][s.c - 1]) {
                q.push(Step(s.r, s.c - 1));
                route[s.r][s.c - 1].c = s.c;
                route[s.r][s.c - 1].r = s.r;
                visited[s.r][s.c - 1] = true;
            }
            if (s.c + 1 <= 4 && maze[s.r][s.c + 1] == 0 && !visited[s.r][s.c + 1]) {
                q.push(Step(s.r, s.c + 1));
                route[s.r][s.c + 1].c = s.c;
                route[s.r][s.c + 1].r = s.r;
                visited[s.r][s.c + 1] = true;
            }
            q.pop();           
        }

    }
    int r = 4, c = 4;    
    while (true) {
            routes.push(Step(r, c));
            if (r == 0 && c == 0)
                break;
            int cur_r = r, cur_c = c;
            r = route[cur_r][cur_c].r;
            c = route[cur_r][cur_c].c;
    }
    while(!routes.empty()) {
        Step temp = routes.top();
        cout <<"(" <<  temp.r << ", " << temp.c << ")" << endl;
        routes.pop();
    }
    return 0;
}