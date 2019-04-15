#include <iostream>
#include <string>
using namespace std;

int main(){
	int n;
	cin >> n;
	while(n--) {
		string str;
		cin >> str;
		int begin, end = str.size();
		for (int i = str.size() - 1; i >=0; --i ) {
			if (str[i] == '.' || str[i] =='/'){
				begin = i;
				cout << str.substr(begin + 1, end - begin - 1);
				cout << str[begin];
				end = begin;
			}
		}
		cout << str.substr(0, end);
	}
	return 0;
}