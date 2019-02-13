#include <iostream>

int main(){
  int N = 0, K = 0;
  while(std::cin >> N >> K){
    int M = -1;
    double housePrice = 200.0;
    for (int i = 1; i < 21; i++){
      if ( (double)(N*i) >= housePrice){
        M = i;
        break;
      }
      housePrice *= (1 + 0.01*K);
    }
    if(M == -1){
      std::cout << "Impossible" << std::endl;
    } else {
      std::cout << M << std::endl;
    }
  }
}
