#include<iostream>
#include<map>
#include<string>
#include<sstream>
using namespace std;

map<string, string> dict;

int main(){
    string key, value;
    string str;
    while (true) {
        getline(cin, str);
        if (str[0] == 0) break;
        stringstream ss(str);
        ss >> value >> key;
        dict[key] = value;
    }
    while (cin >> key) {
        if (dict.count(key) <= 0) {
            cout << "eh" << endl;
        } else {
            cout << dict[key] << endl;
        }
    }
    return 0;
}