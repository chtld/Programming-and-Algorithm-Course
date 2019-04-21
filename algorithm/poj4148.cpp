#include <iostream>
using namespace std;

int main(){
	int d, p, e, i;
	int cases = 0;
	while (true) {
		cases ++;
		cin >> p >> e >> i >> d;
		if (d == -1 && p == -1 && e == -1 && i == -1)
			break;
		for (int j = d + 1; j <= d + 21252; ++ j) {
			if ((j - p) % 23 != 0) continue;
			if ((j - e) % 28 != 0) continue;
			if ((j - i) % 33 != 0) continue;
			printf("Case %d: the next triple peak occurs in %d days.\n", cases, j - d);
		}
	}
	return 0;
}