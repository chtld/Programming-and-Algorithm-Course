#include<iostream>
#include<queue>
using namespace std;

struct cmp
{
    bool operator()(int a, int b) {
        return a < b;
    }
};


int main(){
    int n, k;
    priority_queue<int, vector<int>, cmp> pq;
    cin >> n >> k;
    int val;
    for (int i = 0; i < n; ++ i) {
        cin >> val;
        if (pq.size() < k) {
            pq.push(val);
        } else {
            if (val <= pq.top()) {
                pq.pop();
                pq.push(val);
            }
        }
    }
    cout << pq.top() << endl;
    return 0;
}