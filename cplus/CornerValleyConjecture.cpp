#include <iostream>

void corner(int num) {
  if (num == 1) {
    std::cout << "End";
    return;
  }
  if (num % 2 == 1) {
    std::cout << num << "*3+1="
              << num * 3 + 1 << std::endl;
    num = num * 3 + 1;
  } else {
    std::cout << num << "/" << 2
              << "=" << num / 2 << std::endl;
    num /= 2;
  }
  corner(num);
}

int main(){
  int num = 0;
  std::cin >> num;
  corner(num);
  return 0;
}
