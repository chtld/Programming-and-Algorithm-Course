#include <iostream>
#include <list>
using namespace std;

int main(){
	list<int> monkey;
	int n, m;
	while(true) {
		cin >> n >> m;
		if (n == 0 && m == 0) 
			break;
		monkey.clear();
		for (int i = 1; i <= n; ++ i) 
			monkey.push_back(i);
		list<int>::iterator it = monkey.begin();
		while (monkey.size() > 1) {
			for (int i = 1; i < m; ++ i) {
				++ it;
				if (monkey.end() == it)
					it = monkey.begin();
			}
			it = monkey.erase(it);
			if (it == monkey.end())
				it = monkey.begin();
		}
		cout << monkey.front() << endl;
	}
    return 0;
}
