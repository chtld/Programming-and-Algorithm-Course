#include<iostream>
#include<algorithm>

using namespace std;

class Cow{
public:
    int a;
    int b;
    int index;
    Cow(int _a, int _b, int _index) {
        a = _a;
        b = _b;
        index = _index;
    }
    Cow(){}

};
struct cmp1{
    bool operator()(Cow tmp1, Cow tmp2){
        return tmp1.a > tmp2.a;
    }
};
struct cmp2{
    bool operator()(Cow tmp1, Cow tmp2){
        return tmp1.b > tmp2.b;
    }
};
Cow cow[50005];

int main(){
    int n, k;
    cin >> n >> k;
    int a, b;
    for (int i = 0; i < n; ++ i) {
        cin >> a >> b;
        cow[i] = Cow(a, b, i + 1);
    }
    sort(cow, cow + n, cmp1());
    sort(cow, cow + k, cmp2());
    cout << cow[0].index << endl;
    return 0;
}