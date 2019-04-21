#include <iostream>

using namespace std;

int a[1025] = {0};

void NextPermutation(int n){
	int flag = n - 1;
	while (a[flag - 1] > a[flag] && flag != 0) {
		flag --;
	}
	if (flag == 0) {
		for (int i = 0; i < n; ++ i) {
			a[i] = i + 1;
		}
		return;
	}
	for (int i = n - 1; i >= flag; -- i) {
		if (a[i] > a[flag - 1]) {
			int temp = a[i];
			a[i] = a[flag - 1];
			a[flag - 1] = temp;
			break;
		}
	}
	while (flag < n - 1) {
		int temp = a[n - 1];
		a[n - 1] = a[flag];
		a[flag] = temp;
		flag ++;
		n--;
	}
}

int main(){
	int m, n, k;
	int i;
	cin >> m;
	while(m) {
		cin >> n >> k;
		for (int i = 0;i < n; ++ i) {
			cin >> a[i];
		}
		for (int i = 0; i < k; ++ i) {
			NextPermutation(n);
		}
		
		for (int i = 0; i < n; ++ i) {
			cout << a[i] << " ";
		}
		cout << endl;
		m--;
	}
	return 0;
}