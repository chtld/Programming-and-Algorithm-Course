#include<iostream>
#include<algorithm>

using namespace std;

int game1(int *a, int *b, int length) {
    int ans = 0;
    int lefta = 0, righta = length - 1, leftb = 0, rightb = length - 1;
    while (length --) {
        if (a[righta] > b[rightb]) {
            ans += 3;
            righta--;
            rightb--;
        } else if (a[righta] < b[rightb]) {
            ans += 1;
            lefta++;
            rightb--;
        } else {
            if (a[lefta] > b[leftb]) {
                ans += 3;
                lefta++;
                leftb++;
            } else {
                if (a[lefta] < b[rightb]) {
                    ans += 1;
                    lefta++;
                    rightb--;
                } else {
                    ans += 2;
                    lefta++;
                    rightb--;
                }
            }
        }
    }
    return ans;
}


int main(){
    int a[1000], b[1000];
    int n;
    while(cin >> n){
        if (n == 0) break;
        for (int i = 0; i < n; ++ i) {
            cin >> a[i];
        }
        for (int i = 0; i < n; ++ i) {
            cin >> b[i];
        }
        sort(a, a + n);
        sort(b, b + n);
        int ans1 = game1(b, a, n);
        int ans2 = game1(a, b, n);
        ans2 = 4 * n - ans2;
        cout << ans1 << " " << ans2 << endl;
    }
    return 0;
}