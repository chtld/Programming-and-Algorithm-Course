#include<iostream>
#include<queue>
#include<vector>
using namespace std;

struct cmp{
    bool operator()(int a, int b) {
        return a > b;
    }
};

int main(){
    priority_queue<int, vector<int>, cmp> pq;
    vector<int> arr;
    int m, n;
    cin >> m >> n;
    for (int i = 0; i < m; ++ i) {
        int val;
        cin >> val;
        arr.push_back(val);
    }
    for (int i = 0; i < n; ++ i) {
        int val;
        cin >> val;
        pq.push(val);
    }
    int index = 0;
    while (!pq.empty()) {
        int cur = pq.top();
        pq.pop();
        cout << cur << " ";
        if (arr[index] >= cur && index < m) {
            pq.push(arr[index]);
            index++;
        } else if (index == m - 1){
            break;
        } else {
            index++;
        }
    }
    return 0;
}