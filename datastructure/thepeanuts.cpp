#include<iostream>
#include<algorithm>
#include<math.h>
using namespace std;

class Point{
public:
    int x, y;
    int num;
    Point(int _x = 0, int _y = 0, int _num = 0){
        x = _x;
        y = _y;
        num = _num;
    }
};

struct cmp{
    bool operator()(Point a, Point b){
        return a.num > b.num;
    }
};

Point point[2510];
int counts = 0;

int timeit(int x, int y, Point p) {
    return abs(x - p.x) + abs(y - p.y) + 1 + p.x;
}

int time_count(int counts, int limit){
    int res = 0;
    int cur = 0;
    int x = 0, y = point[0].y;
    for (int i = 0; i < counts; ++ i) {
        cur += timeit(x, y, point[i]);
        if (cur <= limit) {
            cur -= point[i].x;
            res += point[i].num;
            x = point[i].x;
            y = point[i].y;
        } else {
            break;
        }
    }
    return res;
}


int main(){
    int t;
    cin >> t;
    while (t--) {
        int m, n, k;
        cin >> m >> n >> k;
        int val;
        counts = 0;
        for (int i = 1; i <= m; ++ i) {
            for (int j = 1; j <= n; ++ j) {
                cin >> val;
                if (val > 0) {
                    point[counts].x = i;
                    point[counts].y = j;
                    point[counts].num = val;
                    counts++;
                }
            }
        }
        sort(point, point + counts, cmp());
        int res = time_count(counts, k);
        cout << res << endl;
    }
    return 0;
}