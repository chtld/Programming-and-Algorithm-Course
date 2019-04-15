int sum(int *a, int n, int (*p)(int)){
	int result = 0;
	for (int i = 0; i < n; ++ i) {
		result += p(a[i]);
	}
	return result;
}