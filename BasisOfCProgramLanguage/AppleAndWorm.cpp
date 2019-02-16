#include <iostream>

int main(){
  int n = 0, x = 0, y = 0;
  std::cin >> n >> x >> y;
  int temp = n*x -y;
  if (temp <= 0) {
	std::cout << 0 << std::endl;
  } else {
	std::cout << temp/x << std::endl;
  }
  return 0;
}
