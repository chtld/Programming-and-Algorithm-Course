#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <cstdlib>
using namespace std;

vector<string> svec;
int getN(string s);
string getStr(string s);
string copy();
bool isInt(string s);
string add();
int find();
int rfind();
void insert();
void reset();
void print();
void printall();

int main(){
	int n = 0;
	string str;
	cin >> n;
	while (n--) {
		cin >> str;
		svec.push_back(str);
	}
	while (true){
		cin >> str;
		if (str == "over") break;
		if (str == "copy")
			copy();
		else if (str == "add")
			add();
		else if (str == "find")
			find();
		else if (str == "rfind")
			rfind();
		else if (str == "insert")
			insert();
		else if (str == "reset")
			reset();
		else if (str == "print")
			print();
		else if (str == "printall")
			printall();
	}
	return 0;
}

int getN(string s){
	if(s == "find") return find();
	else if (s == "rfind") return rfind();
	else return atoi(s.c_str());
}

string getStr(string s){
	if (s == "copy") return copy();
	else if (s == "add") return add();
	else return s;
}

string copy(){
	int N[3] = {0};
	string str;
	for (int i = 0; i < 3; ++ i) {
		cin >> str;
		N[i] = getN(str);
	}
	return svec[N[0] - 1].substr(N[1], N[2]);
}

bool isInt(string s){
	if (s.size() > 5) return false;
	for (int i = 0;i < s.size(); ++ i) {
		if (!(s[i] >= '0' && s[i] <= '9')) 
			return false;
	}
	return true;
}


string add(){
	string s1, s2;
	cin >> s1;
	s1 = getStr(s1);
	cin >> s2;
	s2 = getStr(s2);
	if (isInt(s1) && isInt(s2)){
		int a = atoi(s1.c_str());
		int b = atoi(s2.c_str());
		int c = a + b;
		stringstream ss;
		ss << c;
		string str;
		ss >> str;
		return str;
	}
	return s1 + s2;
}

int find(){
	string s1, s2;
	cin >> s1;
	s1 = getStr(s1);
	cin >> s2;
	int index = getN(s2);
	return svec[index - 1].find(s1.c_str());
}

int rfind(){
	string s1, s2;
	cin >> s1;
	s1 = getStr(s1);
	cin >> s2;
	int index = getN(s2);
	return svec[index - 1].rfind(s1.c_str());
}

void insert(){
	string s1, s2, s3;
	cin >> s1;
	s1 = getStr(s1);
	cin >> s2;
	int N = getN(s2);
	cin >> s3;
	int X = getN(s3);
	svec[N-1].insert(X, s1.c_str());
}

void reset(){
	string s1, s2;
	cin >> s1;
	s1 = getStr(s1);
	cin >> s2;
	int N = getN(s2);
	svec[N-1] = s1.c_str();
}

void print(){
	string s1;
	cin >> s1;
	int N = getN(s1);
	cout << svec[N-1] << endl;
}

void printall(){
	for (vector<string>::iterator i = svec.begin(); i != svec.end(); ++ i){
		cout << *i << endl;
	}
}
