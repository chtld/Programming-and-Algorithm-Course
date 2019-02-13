#include <iostream>

int main(){
  int k = 0, a = 0;
  int nFive = 0, nOne = 0, nTen = 0;
  std::cin >> k;
  for(int i = 0; i < k; i++){
    std::cin >> a;
    if(a == 1){
      nOne++;
    } else if(a == 5){
      nFive++;
    } else if(a == 10){
      nTen++;
    }
  }
  std::cout << nOne << std::endl << nFive << std::endl << nTen << std::endl;
}
