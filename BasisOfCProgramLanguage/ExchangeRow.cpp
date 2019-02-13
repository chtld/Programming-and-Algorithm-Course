#include <iostream>
#include <iomanip>

int main(){
  int a[5][5] = {0}, n = 0, m = 0;
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) {
      std::cin >> a[i][j];
    }
  }
  std::cin >> n >> m;
  if(n > 4 || n < 0 || m > 4 || m < 0){
    std::cout << "error" << std::endl;
  } else {
    int b[5] = {0};
    for (int i = 0; i < 5; i++) {
      b[i] = a[n][i]; a[n][i] = a[m][i]; a[m][i] = b[i];
    }
    for (int i = 0; i < 5; i++) {
      for (int j = 0; j < 5; j++) {
        std::cout << std::setw(4) << a[i][j];
      }
      std::cout << std::endl;
    }
  }
  return 0;
}
