#include<iostream>
#include<cstring>
using namespace std;

struct Point{
    int x;
    int y;
    int count;
};

int main() {
    int d, n;
    int cases;
    Point point[21];
    int map[1025][1025] = {0};
    int nop = 0, res = 0;
    cin >> cases;
    while (cases--) {
    cin >> d >> n;
    nop = 0, res = 0;
    memset(map, 0, sizeof(map));
    for (int i = 0; i < n; ++ i) {
        cin >> point[i].x >> point[i].y >> point[i].count;
    }
    for (int i = 0; i < n; ++ i) {
        for (int row = point[i].x - d; row <= point[i].x + d; ++ row) {
            if (row >= 0 && row < 1025){
            for (int column = point[i].y - d; column <= point[i].y + d; column ++) {
                if (column >= 0 && column < 1025) {
                map[row][column] += point[i].count;
                if (map[row][column] > res) {
                    nop = 1;
                    res = map[row][column];
                } else if (map[row][column] == res) {
                    nop ++;
                }
                }
            }
            }
        }
    }
    cout << nop << " " << res << endl;
    }
    return 0;
}