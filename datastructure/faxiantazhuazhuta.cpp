#include<iostream>

using namespace std;

int father[100005], n, m, tag[100005];

void init(){
    for (int i = 1; i <= n; ++ i) 
        father[i] = i;
    for (int i = 1; i <= n; ++ i)
        tag[i] = 0;
}

int getfather(int i) {
    if (i == father[i])
        return i;
    int tmp = getfather(father[i]);
    tag[i] = (tag[i] + tag[father[i]]) % 2;
    father[i] = tmp;
    return tmp;
}

int main(){
    int t;
    cin >> t;
    while (t--) {
        cin >> n >> m;
        init();
        char c;
        int a, b;
        for (int i = 0; i < m; ++ i) {
            cin >> c >> a >> b;
            int fa = getfather(a);
            int fb = getfather(b);
            if (c == 'A') {
                if (fa != fb) {
                    cout << "Not sure yet." << endl;
                } else {
                    if (tag[a] == tag[b]) {
                        cout << "In the same gang." << endl;
                    } else {
                        cout << "In different gangs." << endl;
                    }
                }
            } else {
                father[fa] = fb;
                tag[fa] = (tag[a] - tag[b] + 1) % 2;
            }
        }
    }
    return 0;
}