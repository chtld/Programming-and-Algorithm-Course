#include <iostream>

using namespace std;

bool hasSeven(int n) {
	while (n) {
		if (n % 10 == 7)
			return true;
		n = n / 10;
	}
	return false;
}


int main(){
	int n;
	cin >> n;
	int sum = 0;
	for (int i = 1; i <= n; ++ i) {
		if (!(i % 7 == 0 || hasSeven(i)))
			sum += i * i;
	}
	cout << sum << endl;
	return 0;
}