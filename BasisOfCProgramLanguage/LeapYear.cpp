#include<iostream>

int main(){
  int a = 0;
  std::cin >> a;
  if ((a % 4 == 0 && a % 100 != 0) || a % 400 == 0) {
    std::cout << "Y" << std::endl;
  } else {
    std::cout << "N" << std::endl;
  }
  return 0;
}
