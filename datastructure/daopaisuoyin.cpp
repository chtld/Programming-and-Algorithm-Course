#include<iostream>
#include<map>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

vector<vector<int>> daopai;

int main(){
    int n;
    cin >> n;
    map<string, int> dict;
    int index = 0;
    for (int i = 1; i <= n; ++ i) {
        int c;
        cin >> c;
        string str;
        for (int j = 0; j < c; ++ j) {
            cin >> str;
            if (dict.count(str) <= 0) {
                vector<int> tmp;
                daopai.push_back(tmp);
                dict[str] = index;
                ++index;
            }
            daopai[dict[str]].push_back(i);
        }
    }
    int m;
    cin >> m;
    string key;
    for (int i = 0; i < m; ++ i) {
        cin >> key;
        if (dict.count(key) <= 0) {
            cout << "NOT FOUND" << endl;
        } else if (daopai[dict[key]].empty()) {
            cout << "NOT FOUND" << endl;
        } else {
            daopai[dict[key]].erase(unique(daopai[dict[key]].begin(), daopai[dict[key]].end()), daopai[dict[key]].end());
            for (int j = 0; j < daopai[dict[key]].size(); ++ j) {
                if (j == 0)
                    cout << daopai[dict[key]][j];
                else
                    cout << " " << daopai[dict[key]][j];
            }
            cout << endl;
        }
    }
    return 0;
}