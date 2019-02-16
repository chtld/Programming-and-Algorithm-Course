#include <iostream>

int main(){
  int n = 0;
  std::cin >> n;
  char a[101][101] = {'\0'};
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      std::cin >> a[i][j];
    }
  }
  int m = 0;
  std::cin >> m;
  for (int k = 2; k <= m; k++) {
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        if (a[i][j] == '@') {
          if (a[i][j + 1] == '.') a[i][j + 1] = ',';
          if (a[i][j - 1] == '.') a[i][j - 1] = ',';
          if (a[i - 1][j] == '.') a[i - 1][j] = ',';
          if (a[i + 1][j] == '.') a[i + 1][j] = ',';
        }
      }
    }
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        if (a[i][j] == ',') a[i][j] = '@';
      }
    }
  }
  int sum = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if(a[i][j] == '@') sum++;
      //std::cout << a[i][j] << std::endl;
    }
  }
  std::cout << sum << std::endl;
  return 0;
}
