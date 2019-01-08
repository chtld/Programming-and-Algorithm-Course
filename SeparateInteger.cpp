#include <iostream>

int main(){
  int integer = 0;
  std::cin >> integer;
  for(int i = 2; i >= 0; i--){
    int temp = 1;
    for(int j = 0; j < i; j++){
      temp *= 10;
    }
    std::cout << integer/temp << std::endl;
    integer -= (integer/temp) * temp;
  }
  return 0;
}
