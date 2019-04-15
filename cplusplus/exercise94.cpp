#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <sstream>
using namespace std;

vector<string> vec;

string GetStr();
int GetN();
bool isInt(string str);
string copy();
string add();
int find();
int rfind();
void insert();
void reset();
void print();
void printall();

int main(){
	int n = 0;
	cin >> n;
	string str;
	for (int i = 0; i < n; ++ i){
		cin >> str;
		vec.push_back(str);
	}
	while (true) {
		cin >> str;
		if (str == "copy") {
			copy();
		} else if (str == "add") {
			add();
		} else if (str == "find") {
			find();
		} else if (str == "rfind") {
			rfind();
		} else if (str == "insert") {
			insert();
		} else if (str == "reset") {
			reset();
		} else if (str == "print") {
			print();
		} else if (str == "printall") {
			printall();
		} else if (str == "over") {
			break;
		}
	}
	return 0;
}

string GetStr(){
	string str;
	cin >> str;
	if (str == "copy") {
		return copy();
	} else if (str == "add") {
		return add();
	} else {
		return str;
	}
}

int GetN(){
	string str;
	cin >> str;
	if (str == "find") {
		return find();
	} else if (str == "rfind") {
		return rfind();
	} else {
		return atoi(str.c_str());
	}
}

bool isInt(string str){
	if(str.size() > 5) return false;
	for (int i = 0; i < str.size(); ++ i) {
		if (str[i] < '0' || str[i] > '9')
			return false;
	}
	return true;
}


string copy(){
	int N = GetN();
	int X = GetN(), L = GetN();
	return vec[N-1].substr(X, L);
}

string add(){
	string s1 = GetStr();
	string s2 = GetStr();
	if (isInt(s1) && isInt(s2)) {
		int x1 = atoi(s1.c_str());
		int x2 = atoi(s2.c_str());
		stringstream ss;
		ss << (x1 + x2);
		string str;
		ss >> str;
		return str;
	} else {
		return (s1 + s2);
	}
}

int find(){
	string S = GetStr();
	int N = GetN();
	return vec[N-1].find(S.c_str());
}

int rfind(){
	string S = GetStr();
	int N = GetN();
	return vec[N-1].rfind(S.c_str());
}

void insert(){
	string S = GetStr();
	int N = GetN();
	int X = GetN();
	vec[N-1].insert(X, S);
}

void reset(){
	string S = GetStr();
	int N = GetN();
	vec[N-1].swap(S);
}

void print(){
	int N = GetN();
	cout << vec[N-1] << endl;
}

void printall(){
	for (int i = 0; i < vec.size(); ++ i) {
		cout << vec[i] << endl;
	}
}
