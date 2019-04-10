#include <iostream>

using namespace std;

int N = 0, M = 0;

void fun(int n, int m) {
	cout << n << " " << m << endl;
	if (n == 0) return;
	else {
		int tmpn = 0;
		int tmpm = 0;
		if (n >= M) {
			tmpm = m + M;
			tmpn = n - M;
		} else { 
			tmpn = M - n;
			tmpm = m + n - (M - n);
		}
		
		return fun(tmpn, tmpm);
	}
}

int main(){
	cin >> N >> M;
	fun(N, 0);
	return 0;
}

