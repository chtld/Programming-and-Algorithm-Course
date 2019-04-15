#include <iostream>

using namespace std;

int main(){
	int n = 0;
	while (cin >> n) {
		for (int i = 0; i < n; ++i) {
			int a = 0;
			cin >> a;
			if (a % 2 == 1) cout << "0 0" << endl;
			else {
				if (a % 4 == 0) cout << a / 4 << " " << a / 2 << endl;
				else cout << (a - 2) / 4 + 1 << " " << a / 2 << endl;
			}
		}
	}
	return 0;
}