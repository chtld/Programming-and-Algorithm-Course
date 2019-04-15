#include <cstdio>

int main(){
	int a[6], x = 0, y = 0, count = 0;
	int u[4] = {0, 5, 3, 1};
	while (scanf("%d %d %d %d %d %d", &a[0], &a[1], &a[2], &a[3], &a[4], &a[5]) != EOF) {
		if (a[0] == 0 && a[1] == 0 && a[2] == 0 && a[3] == 0 && a[4] == 0 && a[5] == 0)
			break;
		count = a[5] + a[4] + a[3] + ((a[2] + 3)/4);
		x = 5*a[3] + u[a[2] % 4];
		if (a[1] > x) {
			count += (a[1] -x + 8) / 9;
		}
		y = count * 36;
		for (int i = 1; i < 6; ++ i) {
			y -= a[i] * (i + 1) *(i + 1);
		}
		if (a[0] > y) {
			count += (a[0] - y + 35) / 36;
		}
		printf("%d\n", count);
	}
	return 0;
}