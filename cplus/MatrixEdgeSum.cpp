#include<iostream>

int main(){
  int a[100][100] = {0}, k = 0, m = 0, n = 0;
  std::cin >> k;
  while (k--) {
    std::cin >> m >> n;
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        std::cin >> *(*(a + i) + j);
      }
    }
    int sum = 0;
    if (m == 1) {
      for (int j = 0; j < n; j++) {
        sum = sum + *(*a + j);
      }
    } else if (n == 1 && m != 1) {
      for (int i = 0; i < m; i++) {
        sum = sum + *(*(a + i));
      }
    } else {
      for (int i = 0; i < m; i++) {
        sum = sum + *(*(a + i)) + *(*(a + i) + n - 1);
      }
      for (int j = 1; j < n - 1; j++) {
        sum = sum + *(*a + j) + *(*(a + m - 1) + j);
      }
    }
    std::cout << sum << std::endl;
  }
  return 0;
}
