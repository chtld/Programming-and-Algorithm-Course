#include <iostream>

using namespace std;

int main(){
	int N = 0;
	int a[100] = {0};
	cin >> N;
	for (int i = 0; i < N; ++ i) {
		cin >> a[i];
	}
	int dp1[100];
	int dp2[100];
	for (int i = 0; i < N; ++ i) {
		dp1[i] = 1;
		dp2[i] = 1;
	}
	for (int i = 1; i < N; ++ i) {
		for (int j = 0; j < i; ++ j) {
			if (a[i] > a[j] && dp1[i] < dp1[j] + 1)
				dp1[i] = dp1[j] + 1;
		}
	}
	
	for (int i = N - 2; i >= 0; -- i) {
		for (int j = N - 1; j > i; -- j) {
			if (a[i] > a[j] && dp2[i] < dp2[j] + 1)
				dp2[i] = dp2[j] + 1;
		}
	}
	
	int min1 = 1000;
	for (int i = 0; i < N; ++ i) {
		if (min1 > N - (dp1[i] + dp2[i] - 1))
			min1 = N - (dp1[i] + dp2[i] - 1);
	}
	cout << min1 << endl;
	return 0;
}