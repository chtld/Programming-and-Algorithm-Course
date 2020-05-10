#include<iostream>
#include<map>
using namespace std;

struct client{
    int id;
    int p;
    client(int _id, int _p) {
        id = _id;
        p = _p;
    }
    bool operator<(const client b) const{
        return p < b.p;
    }
};

int main(){
    map<client, int> dq;
    int flag;
    int k, p;
    while (true) {
        cin >> flag;
        if (flag == 0) break;
        switch (flag) {
        case 1:
            cin >> k >> p;
            dq[client(k, p)] = 1;
            break;
        case 2:
            if (dq.empty()){
                cout << 0 << endl;
            } else {
                map<client, int>::iterator it = dq.end();
                it--;
                cout << it->first.id << endl;
                dq.erase(it);
            }
            break;
        case 3:
            if (dq.empty()){
                cout << 0 << endl;
            } else {
                map<client, int>::iterator it = dq.begin();
                cout << it->first.id << endl;
                dq.erase(it);
            }
            break;
        default:
            break;
        }
    }
    return 0;
}