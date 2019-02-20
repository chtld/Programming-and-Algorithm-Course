#include<iostream>

bool IsIncludeK(int m, int k) {
  int result = 0;
  while (m) {
    if (m % 10 == 3) {
      result++;
    }
    m /= 10;
  }
  if (result == k) {
    return true;
  } else {
    return false;
  }
}


int main(){
  int m = 0, k = 0;
  std::cin >> m >> k;
  if (m % 19 == 0 && IsIncludeK(m, k)) {
    std::cout << "YES" << std::endl;
  } else {
    std::cout << "NO" << std::endl;
  }
}
