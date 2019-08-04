#include<iostream>
#include<cstdio>
#include<algorithm>

using namespace std;

struct Bag{
    int W;
    int D;
};

int N, M, F[13005];
Bag bag[3505];

int main(){
    cin >> N >> M;
    for (int i = 0; i < N; ++ i) {
        cin >> bag[i].W >> bag[i].D;
    }
    for (int j = 0; j <= M; ++ j) {
        if (bag[0].W > j) {
            F[j] = 0;
        } else {
            F[j] = bag[0].D;
        }
    }
    for (int i = 1; i < N; ++ i) {
        for (int j = M; j >= 0; -- j){
            if (bag[i].W <= j)
                F[j] = max(F[j], F[j - bag[i].W] + bag[i].D); 
        }
    }
    cout << F[M] << endl;
    return 0;
}