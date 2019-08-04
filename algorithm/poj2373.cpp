#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;

const int INFINITE = 1 << 30;
const int MAXN = 1010;
const int MAXL = 1000010;

int N, L;
int A, B;
int F[MAXL];
int cowthere[MAXL];
int cowvary[MAXL];
struct Fx
{
    int x;
    int f;
    Fx(int _x_ = 0, int _f_ = 0)
        : x(_x_), f(_f_) {};
    bool operator < (const Fx &a) const {
        return f > a.f;
    }
};

priority_queue<Fx> qFx;

int main(){
    cin >> N >> L;
    cin >> A >> B;
    A <<= 1;
    B <<= 1;
    memset(cowvary, 0, sizeof(cowvary));
    for (int i = 0; i < N; ++ i) {
        int s, e;
        cin >> s >> e;
        ++cowvary[s + 1];
        --cowvary[e];
    }
    int cownum = 0;
    for (int i = 0; i <= L; ++ i) {
        F[i] = INFINITE;
        cownum += cowvary[i];
        cowthere[i] = cownum;
    }
    for (int i = A; i <= B; i += 2) {
        if (!cowthere[i]) {
            F[i] = 1;
            if (i <= B + 2 - A) {
                qFx.push(Fx(i, 1));
            }
        }
    }
    for (int i = B + 2; i <= L; i += 2) {
        if (!cowthere[i]) {
            Fx fx;
            while (!qFx.empty()) {
                fx = qFx.top();
                if (fx.x < i - B) {
                    qFx.pop();
                } else {
                    break;
                }
            }
            if (!qFx.empty()) {
                F[i] = fx.f + 1;
            }
        }
        if (F[i - A + 2] != INFINITE) {
            qFx.push(Fx(i - A + 2, F[i - A + 2]));
        }
    }
    if (F[L] == INFINITE) {
        cout << -1 << endl;
    } else {
        cout << F[L] << endl;
    }
    return 0;
}