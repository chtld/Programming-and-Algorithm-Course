#include <iostream>

int main(){
  int a = 0, b = 0, c = 0;
  scanf("%d,%d,%d", &a, &b, &c);
  if (a + b == c) std::cout << "+" << std::endl;
  else if (a - b == c) std::cout << "-" << std::endl;
  else if (a * b == c) std::cout << "*" << std::endl;
  else if (a / b == c) std::cout << "/" << std::endl;
  else if (a % b == c) std::cout << "%" << std::endl;
  else std::cout << "error" << std::endl;
  return 0;
}
