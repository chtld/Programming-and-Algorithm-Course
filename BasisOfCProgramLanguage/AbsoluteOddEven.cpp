#include <iostream>

int main(){
  int maxOdd = 0, minEven = 100;
  for(int i = 0; i < 6; i++){
    int temp = 0;
    std::cin >> temp;
    if(temp%2 == 1 && temp > maxOdd){
      maxOdd = temp;
    }
    if(temp%2 == 0 && temp < minEven){
      minEven = temp;
    }
  }
  if(minEven == 100){
    minEven = 0;
  }
  std::cout << ((maxOdd > minEven) ? (maxOdd - minEven) : (minEven - maxOdd)) << std::endl;
  return 0;
}
