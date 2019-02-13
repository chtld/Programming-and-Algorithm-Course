#include <iostream>

int main(){
  int a = 0, flag = 0;
  while (std::cin >> a) {
    flag = 0;
    if (a % 3 == 0) {
      flag += 3;
      std::cout << 3 << " ";
    }
    if (a % 5 == 0) {
      flag += 5;
      std::cout << 5 << " ";
    }
    if (a % 7 == 0) {
      flag += 7;
      std::cout << 7 << " ";
    }
    if (flag == 0) {
      std::cout << "n";
    }
    std::cout << std::endl;
  } 
  return 0;
}
