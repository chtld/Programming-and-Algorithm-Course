#include<iostream>

int main(){
  int N = 0, a[100][100] = {0};
  std::cin >> N;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      std::cin >> a[i][j];
    }
  }
  int nCell = 0;
  for (int i = 1; i < N - 1; i++) {
    for (int j = 1; j < N - 1; j++) {
      if (a[i - 1][j] - a[i][j] >= 50 &&
          a[i + 1][j] - a[i][j] >= 50 &&
          a[i][j + 1] - a[i][j] >= 50 &&
          a[i][j - 1] - a[i][j] >= 50)
        nCell++;
    }
  }
  std::cout << nCell << std::endl;
  return 0;
}
