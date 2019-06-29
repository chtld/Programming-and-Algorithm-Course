#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

int fileStructure(int level, string dir, int ncase) {
    vector<string> v;
    for (int i = 1; i <= level; ++ i)
        cout << "|     ";
    if (level != 0) 
        cout << dir << endl;
    int t = 0;
    while (true) {
        string s;
        cin >> s;
        if(s[0] == '#') 
            return 0;
        if (t == 0 && level == 0) {
            cout << "DATA SET " << ncase << ":" << endl;
            cout << dir << endl;
            t = 1;
        }
        if (s[0] == '*')
            break;
        if (s[0] == 'f')
            v.push_back(s);
        if (s[0] == 'd')
            fileStructure(level + 1, s, ncase);
        if (s[0] == ']')
            break;
    }
    sort(v.begin(), v.end());
    vector<string>::iterator it = v.begin();
    for (; it != v.end(); it ++) {
        for (int i = 1; i <= level; i++) {
            cout << "|     ";
        }
        cout << *it << endl;
    }
    return 1;
}

int main(){
    int ncase = 0;
    while (true) {
        ncase++;
        int end = fileStructure(0, "ROOT", ncase);
        if (end == 0) break;
        cout << endl;
    }
    return 0;
}