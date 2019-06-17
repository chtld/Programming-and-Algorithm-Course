#include <cstdio>

int main(){
	int N, a, b, c, d, cube[101];
	scanf("%d", &N);
	for (int i = 2; i <= N; ++ i) {
		cube[i] = i * i * i;
	}
	for (int a = 6; a <= N; ++ a)
		for (int b = 2; b < a; ++ b)
			for (int c = b; c < a; ++ c)
				for (int d = c; d < a; ++ d){
					if(cube[a] == cube[b] + cube[c] + cube[d])
						printf("Cube = %d, Triple = (%d,%d,%d)\n", a, b, c, d);
				}
		
	return 0;
}