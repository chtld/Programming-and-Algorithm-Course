#include <iostream>

int main(){
  int n = 0, sum = 0, sumGold = 0, sumSilver = 0, sumCopper = 0;
  std::cin >> n;
  for(int i = 0; i < n; i++){
    int nGold = 0, nSilver = 0, nCopper = 0;
    std::cin >> nGold >> nSilver >> nCopper;
    sumGold += nGold;
    sumSilver += nSilver;
    sumCopper += nCopper;
  }
  sum = sumGold + sumSilver + sumCopper;
  std::cout << sumGold << " " << sumSilver << " " << sumCopper << " " << sum <<std::endl; 
  return 0;
}
