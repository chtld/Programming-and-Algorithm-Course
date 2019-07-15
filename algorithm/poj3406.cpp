#include<iostream>
#include<algorithm>
#include<cstdio>

using namespace std;

int a[20001];

int main(){
    int N, B;
    int sum = 0, count = 0;
    cin >> N >> B;
    for (int i = 0; i < N; ++ i) {
        cin >> a[i];
    }
    sort(a, a + N);
    for (int i = N - 1; i >= 0; -- i) {
        if (sum >= B) break;
        sum += a[i];
        count ++;
    }
    cout << count << endl;
    return 0;
}
