#include <iostream>

int main(){
  int n = 0, x[100] = {0};
  std::cin >> n;
  for (int i = 0; i < n; i++) {
    std::cin >> x[i];
  }
  for (int i = 0; i < n; i++) {
    if (x[i] == i) {
      std::cout << i << std::endl;
      return 0;
    }
  }
  std::cout << "N" << std::endl;
  return 0;
}
