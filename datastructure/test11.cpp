#include<iostream>
#include<cstdio>
#include<set>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

vector<string> split(string str, string pattern)
{
	string::size_type pos;
	vector<string> result;
	str += pattern;//扩展字符串以方便操作
	int size = str.size();
	for (int i = 0; i < size; i++)
	{
		pos = str.find(pattern, i);
		if (pos < size)
		{
			string s = str.substr(i, pos - i);
			result.push_back(s);
			i = pos + pattern.size() - 1;
		}
	}
	return result;
}


int main() {
	string str;
	int n;
	cin >> str >> n;
	set<string> st;
	st.insert(str);
	vector<vector<string>> group;
	for (int i = 0; i < n; ++i) {
		string temp;
		cin >> temp;
		group.push_back(split(temp, string(",")));
	}
    // cerr << "hello world" << endl;
    vector<vector<string>>::iterator iter;
	for (iter = group.begin(); iter != group.end(); iter++) {
		vector<string> tmp = *iter;
        // cerr << "hello world" << endl;
		for (set<string>::iterator it = st.begin(); it != st.end(); ++ it) {
			vector<string>::iterator ite = find(tmp.begin(), tmp.end(), *it);
			if (ite != tmp.end()) {
				for (int j = 0; j < tmp.size(); ++j) {
					st.insert(tmp[j]);
				}
			}
		}
	}
	//for (int i = 0; i < n; ++i) {
	//	vector<string> tmp = group[i];
	//	for (set<string>::iterator it = st.begin(); it != st.end(); ++it) {
	//		vector<string>::iterator ite = find(tmp.begin(), tmp.end(), *it);
	//		if (ite != tmp.end()) {
	//			for (int j = 0; j < tmp.size(); ++j) {
	//				st.insert(tmp[i]);
	//			}
	//		}
	//	}
	//}
	cout << st.size() << endl;
	getchar();
	return 0;
}