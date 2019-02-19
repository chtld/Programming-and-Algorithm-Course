#include<iostream>

int main(){
  int a[100][100] = {0}, k = 0, m = 0, n = 0;
  std::cin >> k;
  while (k--) {
    std::cin >> m >> n;
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        std::cin >> *((*a) + i * m + j);
      }
    }
    int sum = 0;
    if (m == 1) {
      for (int j = 0; j < n; j++) {
        sum = sum + *(a[0] + j);
      }
    } else if (n == 1 && m != 1) {
      for (int i = 0; i < m; i++) {
        sum = sum + *(a[0] + i * m);
      }
    } else {
      for (int i = 0; i < m; i++) {
        sum = sum + *(a[0] + i * m) + *(a[0] + i * m + n - 1);
      }
      for (int j = 1; j < n - 1; j++) {
        sum = sum + *(a[0] + j) + *(a[0] + (m - 1) * m + j);
      }
    }
    std::cout << sum << std::endl;
  }
  return 0;
}
