#include <cstdio>

using namespace std;

int main(){
	int p, e, i, d;
	int cases = 0;
	while (true) {
		scanf("%d%d%d%d", &p, &e, &i, &d);
		if (p == -1) break;
		cases ++;
		int j = 0;
		for (j = d + 1; j <= d + 21252; ++ j)
			if ((j - p) % 23 == 0) break;
		for (; j <= d + 21252; j = j + 23) 
			if ((j - e) % 28 == 0) break;
		for (; j <= d + 21252; j = j + 28*23)
			if ((j - i) % 33 == 0) break;
		printf("Case %d: the next triple peak occurs in %d days.\n", cases, j - d);
	}
	return 0;
}