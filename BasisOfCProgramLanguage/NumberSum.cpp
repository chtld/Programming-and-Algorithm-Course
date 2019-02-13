#include <iostream>

int main(){
  int a = 0, sum = 0;
  std::cin >> a;
  for (int i = 0; i < 5; i++){
    int x = 0;
    std::cin >> x;
    if (x < a) {
      sum += x;
    }
  }
  std::cout << sum << std::endl;
  return 0;
}
