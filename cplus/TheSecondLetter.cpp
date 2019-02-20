#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <string>
using namespace std;

bool cmp(const pair<char, int> &a, const pair<char, int> &b) {
  return a.second > b.second;
}

int main(){
  string s;
  getline(cin, s);
  unordered_map<char, int> m;
  for (int i = 0; i < s.size(); i++) {
    if (s[i] >= 'a' && s[i] <= 'z') {
      s[i]-=32;
    }
    if (s[i] >= 'A' && s[i] <= 'Z') {
      m[s[i]]++;
    }
  }
  vector<pair<char, int>> vec(m.begin(), m.end());
  sort(vec.begin(), vec.end(), cmp);
  for (auto iter = vec.begin(); iter != vec.end(); iter++) {
    if ((*iter).second < vec[0].second) {
      cout << (*iter).first << "+" << (char)((*iter).first + 32)
           << ":" << (*iter).second << endl;
      break;
    }
  }
  return 0;
}
