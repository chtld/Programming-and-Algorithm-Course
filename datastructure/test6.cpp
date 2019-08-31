#include<iostream>

using namespace std;

struct Num {
    int i;
    int j;
} num[46];

int main(){
    for (int i = 1; i <= 5; ++ i) {
        for (int j = 1; j <= 5; ++ j) {
            num[(i - 1) * 5 + j].i = i;
            num[(i - 1) * 5 + j].j = j;
        }
    }
    int a[6];
    while (true) {
        for (int i = 0; i < 6; ++ i) {
            cin >> a[i];
        }
        bool flag = false;
        for (int i = 0; i < 6; ++ i) {
            for (int j =0; j < 6; ++ j) {
                if (j != i && (num[a[i]].i == num[a[j]].i) || num[a[i]].j == num[a[j]].j) {
                    flag = true;
                    break;
                }
            }
            if (!flag) {
                break;
            }
        }
        if (flag) {
            cout << 1 << endl;
        } else {
            cout << 0 << endl;
        }
    }

    return 0;
}