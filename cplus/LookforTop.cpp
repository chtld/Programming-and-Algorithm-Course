#include <iostream>
int main() {
  int m = 0, n = 0, a[20][20] = {0};
  std::cin >> m >> n;
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      std::cin >> a[i][j];
    }
  }
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      bool top = (i - 1 < 0 || a[i - 1][j] <= a[i][j]);
      bool bottom = (i + 1 >= m || a[i + 1][j] <= a[i][j]);
      bool left = (j - 1 < 0 || a[i][j - 1] <= a[i][j]);
      bool right = (j + 1 >= n || a[i][j + 1] <= a[i][j]);
      if (top && bottom && left && right){
        std::cout << i << " " << j <<std::endl;
      }
    }
  }
  return 0;
}
