#include <iostream>

using namespace std;

int main(){
	int n = 0, m = 0;
	while (true) {
		cin >> n >> m;
		if (n == 0 && m == 0)
			break;
		int a[301] = {0};
		int count = n;
		int index = -1;
		while (count > 1) {	
			int i = 0;
			while (i < m) {
				index ++;
				if (index == n) index = 0;
				if (a[index] == 0) {
					i++;
					if (i == m)
						a[index] = 1;
				}	
			}
			count --;
		}
		int flag = 0;
		for (int i = 0; i < n; ++ i) {
			if (a[i] == 0) {
				flag = i;
				break;
			}
		}
		cout << flag + 1 << endl;
	}
	return 0;
}