#include <iostream>

void move(int m, char x, char y, char z){
  if (m == 1) {
    std::cout << "把一个盘子从" << x << "移动到" << z << std::endl;
  } else {
    move(m - 1, x, z, y);
    std::cout << "把一个盘子从" << x << "移动到" << z << std::endl;
    move(m - 1, y, x, z);
  }
}


int main(){
  int n;
  std::cout << "请输入盘子数n = ";
  std::cin >> n;
  std::cout << "在三根柱子上移动" << n
            <<"只盘子的步骤为" << std::endl;
  move(n, 'A', 'B', 'C');
  return 0;
}
