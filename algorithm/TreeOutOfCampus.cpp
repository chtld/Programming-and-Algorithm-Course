#include <cstdio>
#include <cstring>

int main(){
	int L = 0, M = 0, a[10001];
	while (scanf("%d %d", &L, &M) != EOF) {
		memset(a, 0, sizeof(a));
		for (int i = 0; i < M; ++ i) {
			int start = 0, end = 0;
			scanf("%d %d", &start, &end);
			for (int j = start; j <= end; ++ j) {
				a[j] = 1;
			} 
		}
		int numberOfTree = 0;
		for (int i = 0; i <= L; ++ i) {
			if (a[i] == 0) {
				numberOfTree++;
			}
		}
		printf("%d\n", numberOfTree);
	}
	return 0;
}
