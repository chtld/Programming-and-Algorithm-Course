#include<iostream>
#include<set>
#include<cstdio>
using namespace std;

set<int> index[1005];

int main(){
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++ i) {
        int c;
        scanf("%d", &c);
        int val;
        for (int j = 0; j < c; ++ j) {
            cin >> val;
            index[i].insert(val);
        }
    }
    int m;
    scanf("%d", &m);
    for (int i = 0; i < m; ++ i) {
        set<int> a, b;
        int f;
        bool flag = true;
        for (int j = 1; j <= n; ++ j) {
            scanf("%d", &f);
            if (f == 1 && flag) {
				flag = false;
                for (set<int>::iterator iter = index[j].begin(); iter != index[j].end(); ++ iter)
                    a.insert(*iter);
            } else if (f == 1 && !flag) {
                for (set<int>::iterator iter = a.begin(); iter != a.end();) {
                    if (index[j].count(*iter) <= 0) {
                        a.erase(iter++);
                    } else {
						iter++;
					}
                }
            } else if (f == -1) {
                for (set<int>::iterator iter = index[j].begin(); iter != index[j].end(); ++ iter)
                    a.erase(*iter);
            }

        }
		//for (set<int>::iterator iter = b.begin(); iter != b.end(); ++iter) {
        //    a.erase(*iter);
        //}
        if (a.empty()) {
            printf("NOT FOUND\n");
        } else {
			bool flag = true;
            for (set<int>::iterator iter = a.begin(); iter != a.end(); ++ iter) {
                if (flag) {
					printf("%d", *iter);
					flag = false;
				} else
					printf(" %d", *iter);
            }
            printf("\n");
        }
    }
    return 0;
}