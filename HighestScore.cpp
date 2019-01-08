#include <iostream>

int main(){
  int n = 0, maxScore = 0;
  std::cin >> n;
  for(int i = 0; i < n; i++){
    int score  = 0;
    std::cin >> score;
    if(score > maxScore){
      maxScore = score;
    }
  }
  std::cout << maxScore << std::endl;
  return 0;
}
