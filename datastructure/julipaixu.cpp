#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstdio>
using namespace std;

struct Point{
    double x, y, z;
    int index;
    Point(double _x = 0.0, double _y = 0.0, double _z = 0.0, int _index = 0){
        x = _x; y = _y; z = _z;
        index = _index;
    }
};

struct Dist{
    Point a;
    Point b;
    double distance;
    Dist(Point _a, Point _b, double distanced) {
        a = _a;
        b = _b;
        distance = distanced;
    }
    Dist(){
        a = Point();
        b = Point();
        distance = 0.0;
    }
    /*
    bool operator<(const Dist& d){
        if (distance > d.distance) {
            return true;
        } else if (distance < d.distance){
            return false;
        } else {
            if (a.index < d.a.index) {
                return true;
            } else if (a.index > d.a.index) {
                return false;
            } else {
                return b.index < d.b.index;
            };
        }
    }
    */
};

struct cmp{
    bool operator()(Dist& d1, Dist& d2){
        if (d1.distance > d2.distance) {
            return true;
        } else if (d1.distance < d2.distance){
            return false;
        } else {
            if (d1.a.index < d2.a.index) {
                return true;
            } else if (d1.a.index > d2.a.index) {
                return false;
            } else {
                return d1.b.index < d2.b.index;
            };
        }
    }
};

double compute(Point a, Point b){
    double dx = a.x - b.x;
    double dy = a.y - b.y;
    double dz = a.z - b.z;
    return sqrt(dx * dx + dy * dy + dz * dz);
}

int main(){
    Point point[15];
    Dist dist[225];
    int n;
    cin >> n;
    int x, y, z;
    for (int i = 0; i < n; ++ i) {
        cin >> point[i].x >> point[i].y >> point[i].z;
        point[i].index = i;
    }
    int count = 0;
    for (int i = 0; i < n; ++ i) {
        for (int j = i + 1; j < n; ++ j) {
            dist[count] = Dist(point[i], point[j], compute(point[i], point[j]));
            count++;
        }
    }
    sort(dist, dist + count, cmp());
    for (int i = 0; i < count; ++ i) {
        printf("(%.0lf,%.0lf,%.0lf)-(%.0lf,%.0lf,%.0lf)=%.2lf\n", dist[i].a.x, dist[i].a.y, dist[i].a.z,
                                              dist[i].b.x, dist[i].b.y, dist[i].b.z, dist[i].distance);
    }
    return 0;
} 