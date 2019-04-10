#include <iostream>
#include <map>
#include <list>
#include <string>
#include <iterator>
using namespace std;

int main(){
	map<int , list<int>> mymap;
	
	string str;
	int n = 0;
	cin >> n;
	while(n--) {
		cin >> str;
		switch (str[0]) {
			case 'n':
			{
				int id = 0;
				cin >> id;
				mymap[id] = list<int>();
				break;
			}
			case 'a':
			{
				int id = 0, num = 0;
				cin >> id >> num;
				mymap[id].push_back(num);
				break;
			}
			case 'm':
			{
				int id1 = 0, id2 = 0;
				cin >> id1 >> id2;
				mymap[id1].sort();
				mymap[id2].sort();
				mymap[id1].merge(mymap[id2]);
				break;
			}
			case 'u':
			{
				int id = 0;
				cin >> id;
				mymap[id].sort();
				mymap[id].unique();
				break;
			}
			case 'o':
			{
				int id = 0;
				cin >> id;
				mymap[id].sort();
				typename list<int>::iterator i = mymap[id].begin();
				for (; i != mymap[id].end(); ++ i) {
					cout << *i << " "; 
				}
				cout << endl;
				break;
			}
			default:;
		}
	}
	return 0;
}