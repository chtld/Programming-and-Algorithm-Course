#include <iostream>
#include <cstdio>
using namespace std;

int puzzle[7][8], press[7][8];

bool guess(){
	for (int i = 2; i <= 6; ++ i) {
		for (int j = 1; j <= 6; ++ j) {
			press[i][j] = press[i - 1][j] ^ puzzle[i - 1][j] 
			^ press[i - 1][j - 1] ^ press[i - 1][j + 1] ^ press[i - 2][j];
		}
	}
	for (int j = 1; j <= 6; ++ j) {
		if (press[6][j] == 1) return false;
	}
	return true;
}

void enumrate(){
	for (int i = 0; i < (1<<6); ++ i) {
		int k = i;
		for (int j = 1; j <= 6; ++ j) {
			press[1][j] = k % 2;
			k = k / 2;
		}
		if (guess()) break;
	}
	for (int i = 1; i <= 5; ++ i) {
		for (int j = 1; j <= 6; ++ j) {
			printf("%d ", press[i][j]);
		}
		printf("\n");
	}
}

int main(){
	for (int i = 1; i <= 5; ++ i) {
		for (int j = 1; j <= 6; ++ j ) {
			scanf("%d", &puzzle[i][j]);
		}
	}
	enumrate();
	return 0;
}