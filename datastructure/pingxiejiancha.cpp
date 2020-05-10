#include<iostream>
#include<vector>
#include<string>
using namespace std;

bool equal(vector<string>& dict, const string& temp) {
    for (int i = 0; i < dict.size(); ++ i) {
        if (dict[i] == temp) {
            cout << temp << " is correct" << endl;
            return true;
        }
    }
    return false;
}

bool replacesimiliar(const string& a, const string& b) {
    if (a.size() != b.size()) return false;
    int count = 0;
    for (int i = 0; i < a.size(); ++ i) {
        if (a[i] != b[i]) {
            count++;
            if (count >= 2) return false;
        }
    }
    return true;
}

bool deletesimiliar(const string& a, const string& b) {
    if (a.size() <= b.size()) return false;
    if (a.size() - b.size() > 1) return false;
    for (int i = 0, k = 0; i < b.size();) {
        if (a[k] != b[i]) {
            k++;
            if (k - i >= 2) return false;
        } else {
            k++;
            i++;
        }
    }
    return true;
}


void similiar (vector<string>& dict, const string& temp) {
    vector<string> res;
    for (int i = 0; i < dict.size(); ++ i) {
        if (deletesimiliar(dict[i], temp))
            res.push_back(dict[i]);
        if (deletesimiliar(temp, dict[i]))
            res.push_back(dict[i]);
        if (replacesimiliar(dict[i], temp))
            res.push_back(dict[i]);
    }
    cout << temp << ":";
    if (!res.empty()) { 
        for (int i = 0; i < res.size(); ++ i) {
            cout << " " << res[i];
        }
    }
    cout << endl;
}


int main() {
    vector<string> dict;
    string temp;
    while (true) {
        cin >> temp;
        if (temp == "#") break;
        dict.push_back(temp);
    }
    while (true) {
        cin >> temp;
        if (temp == "#") break;
        if (equal(dict, temp)) continue;
        similiar(dict, temp);
    }
}