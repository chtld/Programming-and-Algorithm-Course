#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

int ans[10], part[10];
bool re = false;
int diff;

void dfs(int target, int num) {
    if (num <= target) {
        if (target - num < diff) {
            re = false;
            diff = target - num;
            for (int i = 1; i < part[0]; ++ i) {
                ans[i] = part[i];
            }
            ans[0] = part[0];
            ans[ans[0]] = num;
        } else if (target - num == diff) {
            re = true;
        }
    } else {
        for (int i = 10; i <= 100000; i *= 10) {
            part[part[0]++] = num % i;
            if (num / i > 0 && target > num % i)
                dfs(target - num % i, num / i);
            part[0]--;
        }
    }
}

int main(){
    int target, num;
    while (true) {
        cin >> target >> num;
        if (target == 0 && num == 0)
            return 0;
        memset(ans, 0, sizeof(ans));
        memset(part, 0, sizeof(part));
        diff = 1 << 30;
        re = false;
        part[0] = 1;
        dfs(target, num);
        if (re) {
            cout << "rejected" << endl;
        } else if (!ans[0]){
            cout << "error" << endl; 
        } else {
            cout << target - diff << " ";
            for (int i = 0; i < ans[0]; ++ i) {
                cout << ans[ans[0] - i] << " ";
            }
            cout << endl;
        }
    }
    return 0;
}