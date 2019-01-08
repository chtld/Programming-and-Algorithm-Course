#include <iostream>

int main(){
  int water = 20000, h = 0, r = 0;
  double pi = 3.14159;
  std::cin >> h >> r;
  int nWater = (int) water/(pi*r*r*h) + 0.99;
  std::cout << nWater << std::endl;
  return 0;
}
