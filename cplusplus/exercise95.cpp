#include <iostream>
#include <map>
using namespace std;

int main(){
	multimap<int, int> vip;
	vip.insert(multimap<int, int>::value_type(1000000000, 1));
	int n = 0;
	cin >> n;
	int id = 0, attack = 0;
	while (n--) {
		cin >> id >> attack;
		multimap<int, int>::iterator temp = vip.insert(multimap<int, int>::value_type(attack, id));
		multimap<int, int>::iterator temp1 = temp;
		multimap<int, int>::iterator temp2 = temp;
		if (temp == vip.begin()) temp++;
		else if(temp == vip.end()) temp--;
		else {
			temp1--;
			temp2++;
			if(attack - temp1->first <= temp2->first - attack) {
				temp = temp1;
			} else {
				temp = temp2;
			}
		}
		cout << id << " " << temp->second << endl;
	}
	return 0;
}