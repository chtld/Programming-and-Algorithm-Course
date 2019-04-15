#include <iostream>
#include <set>
using namespace std;

int main(){
	multiset<int>  intset;
	set<int> tempset;
	string str;
	int n, x;
	cin >> n;
	while (n--) {
		cin >> str;
		if (str == "add") {
			cin >> x;
			tempset.insert(x);
			multiset<int>::iterator p = intset.insert(x);
			cout << intset.count(x) << endl;
		} else if (str == "del") {
			cin >> x;
			cout << intset.count(x) << endl;
			intset.erase(intset.lower_bound(x), intset.upper_bound(x));
		} else if (str == "ask") {
			cin >> x;
			set<int>::iterator temp = tempset.find(x);
			if (temp != tempset.end()) {
				cout << 1 << " ";
			} else {
				cout << 0 << " ";
			}
			cout << intset.count(x) << endl;
		} else {
			cout << "error.\n" << endl;
		}
	}

	return 0;
}