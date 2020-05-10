#include<iostream>
#include<map>
#include<climits>
#include<stack>
using namespace std;

int P, Q, R;
struct Dist{
    long length;
    int pre;
};
Dist D[35][35];
map<string, int> str2index;
map<int, string> index2str;

void init(){
    for (int i = 0; i < P; ++ i) {
        for (int j = 0; j < P; ++ j) {
            if (i == j) {
                D[i][j].length = 0;
                D[i][j].pre = i;
            } else {
                D[i][j].length = INT_MAX;
                D[i][j].pre = -1;
            }
        }
    }
}

void build(){
    cin >> Q;
    for (int k = 0; k < Q; ++ k) {
        string from, to;
        int distance;
        cin >> from >> to >> distance;
        int i = str2index[from];
        int j = str2index[to];
        if (distance < D[i][j].length) {
            D[i][j].length = distance;
            D[j][i].length = distance;
            D[i][j].pre = i;
            D[j][i].pre = j;
        }
    }
}

void shortpath(){
    for (int k = 0; k < P; ++ k) {
        for (int i = 0; i < P; ++ i) {
            for (int j = 0; j < P; ++ j) {
                if (D[i][j].length > D[i][k].length + D[k][j].length) {
                    D[i][j].length = D[i][k].length + D[k][j].length;
                    D[i][j].pre = D[k][j].pre;
                }
            }
        }
    }
    return;
}

void path(int from, int to){
    stack<int> sta;
    sta.push(to);
    while (from != to) {
        to = D[from][to].pre;
        sta.push(to);
        //cout << index2str[to] << " ";
    }
    //cout << endl;
    int start = sta.top();
    sta.pop();
    cout << index2str[start];
    while (!sta.empty()){
        cout << "->" << "(";
        int end = sta.top();
        sta.pop();
        cout << D[start][end].length << ")" << "->" << index2str[end];
        start = end;
    }
    cout << endl;
}


int main(){
    cin >> P;
    for (int i = 0; i < P; ++ i) {
        string str;
        cin >> str;
        str2index[str] = i;
        index2str[i] = str;
    }
    init();
    build();
    shortpath();
    cin >> R;
    for (int i = 0; i < R; ++ i) {
        string from, to;
        cin >> from >> to;
        int fi = str2index[from];
        int ti = str2index[to];
        path(fi, ti);
    }
    return 0;
}
