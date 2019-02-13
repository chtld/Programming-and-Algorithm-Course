#include <iostream>

int main(){
  int n = 0;
  std::cin >> n;
  switch(100){
  case 100:
    std::cout << n/100 << std::endl;
    n -= (n/100)*100;
  case 50:
    std::cout << n/50 << std::endl;
    n -= (n/50)*50;
  case 20:
    std::cout << n/20 << std::endl;
    n -= (n/20)*20;
  case 10:
    std::cout << n/10 << std::endl;
    n -= (n/10)*10;
  case 5:
    std::cout << n/5 << std::endl;
    n -= (n/5)*5;
  default:
    std::cout << n << std::endl;
  }
  return 0;
}
