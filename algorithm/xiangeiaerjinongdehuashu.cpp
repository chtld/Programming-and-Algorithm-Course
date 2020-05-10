#include <cstring>
#include <queue>
#include <iostream>
using namespace std;
#define MAX (201 * 201)
char a[MAX];
int deep[MAX];
int r, c, sum;

int canMoveStep(int pos, int d);
int bfs(int start, int end) {
    memset(deep, 0, sizeof(deep));
    if (start == end) return 0;
    std::queue<int> q;
    q.push(start);
    while(!q.empty()) {
        int pos = q.front();
        q.pop();
        for(int i = 0; i < 4; i++) {
            int move = canMoveStep(pos, i);
            if (move) {
                int newPos = pos + move;
                if (a[newPos] !='#' && !deep[newPos]) {
                    deep[newPos] = deep[pos] + 1;
                    if (newPos == end) return deep[newPos];
                    q.push(newPos);
                }
            }
        }
    }
    return -1;
}

int canMoveStep(int pos, int d) {
    if (d == 0) return pos % c != 0 ? -1 : 0;   //第0列不能向左搜索
    if (d == 1) return (pos + 1) % c != 0;   //最后一列不能向右搜索
    if (d == 2) return pos < c ? 0 : -c;     //第0行不能向上搜索
    if (d == 3) return pos >= (sum - c) ? 0 : c;   //最后一行不能向下搜索
    return 0;
}

void print(int result)
{
    if (result == -1) {
        cout << "oop!" << endl;
    } else {
        cout << result << endl;
    }
}

int main() {
//  freopen("in.txt", "r", stdin);
    int t, start = 0, end = 0;
    cin >> t;
    while(t--) {
        cin >> r >> c;
        sum = r * c;
        for(int i = 0; i < sum; i++) {
            cin >> a[i];
            if (a[i] == 'S') {
                start = i;
            }else if (a[i] == 'E') {
                end = i;
            }
        }
        print(bfs(start, end));
    }
    return 0;
}